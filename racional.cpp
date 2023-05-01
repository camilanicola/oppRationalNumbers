#include "racional.h"

#include <cmath>
#include <iostream>
int MaximoDivisorComum(int num, int den){
  if(num<0) num=abs(num);
  int resto;
  while(den!=0){
    resto=num%den;
    num=den;
    den=resto;
  }
  return num;
}
void Racional::Simplificar() {
  if(denominador_<0){
    this->numerador_=-numerador_;
    this->denominador_=abs(denominador_);
  }
  int mdc=MaximoDivisorComum(this->numerador_, this->denominador_);
  this->numerador_=numerador_/mdc;
  this->denominador_=denominador_/mdc;
  
}

Racional::Racional() {
  numerador_=0;
  denominador_=0;
}

Racional::Racional(int n)  {
  numerador_=n;
  denominador_=1;
  Simplificar();
}

Racional::Racional(int n, int d) {
  numerador_=n;
  if(d!=0) denominador_=d;
  else denominador_=1;
  Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  Racional s(-this->numerador_, this->denominador_);
  return s;
}

Racional Racional::somar(Racional k) const {
  Racional f(0,1);
  if(this->denominador_==k.denominador_){
    f.denominador_=this->denominador_;
    f.numerador_=this->numerador_+k.numerador_;
    
  }
  else{
    f.denominador_= (this->denominador_*k.denominador_)/MaximoDivisorComum(this->denominador_, k.denominador_);
  
  
  int a, b;
  a=(f.denominador_/this->denominador_)*this->numerador_;
  b=(f.denominador_/k.denominador_)*k.numerador_;

  f.numerador_=a+b;
  }
  f.Simplificar();
  return f;
}

Racional Racional::subtrair(Racional k) const {
   Racional f(0,0);
  if(this->denominador_==k.denominador_){
    f.denominador_=this->denominador_;
    f.numerador_=this->numerador_-k.numerador_;
    
  }
  else{
    f.denominador_= (this->denominador_*k.denominador_)/MaximoDivisorComum(this->denominador_, k.denominador_);
  
  
  int a, b;
  a=(f.denominador_/this->denominador_)*this->numerador_;
  b=(f.denominador_/k.denominador_)*k.numerador_;

  f.numerador_=a-b;
  }
  f.Simplificar();
  return f;
}

Racional Racional::multiplicar(Racional k) const {
  Racional f(0,0);
  f.denominador_=this->denominador_*k.denominador_;
  f.numerador_=this->numerador_*k.denominador_;
  f.Simplificar();
  return f;
}

Racional Racional::dividir(Racional k) const {
  Racional f(0,0);
  f.numerador_=k.denominador_*this->numerador_;
  f.denominador_=k.numerador_*this->denominador_;
  
  f.Simplificar();
  return f;
}

