/*******************************************/
/* IMPLEMENTACION***************************/
/*******************************************/

/*
  Funcion de Abstraccion

   Dado el objeto del tipo rep r, r = {raiz}, el objeto
  abstracto al que representa es:                       
  a) Arbol nulo, si r.raiz == 0.                      
  b) Arbol con un unico nodo de etiqueta r.raiz->et,
     si r.raiz->hizq == 0 y r.raiz->hder == 0.         

  c)                r.raiz->et
                         /       \
                        /         \
      Arbol(r.raiz->hizq)    Arbol(r.raiz->hder)


  Invariante de Representacion:
  
  Si r.raiz != 0,
  -  r.raiz->padre == 0.
  - Para todo nodo n en el arbol con raiz r.raiz n->hizq<>n->hder y
  - Para todo par de nodos n y m en el arbol con raiz r.raiz si n->hizq=m o n->hder=m 
    entonces m->padre=n

*/

#include <cassert>

//FUNCIONES ASOCIADAS a info_nodo

template <class T>
void ArbolBinario<T>::CopiarInfo(ArbolBinario<T>::info_nodo * &dest, const ArbolBinario<T>::info_nodo*const &source){
	 if (source!=0){
	  dest=new info_nodo(source->et);
	  CopiarInfo(dest->hizq,source->hizq);
	  if (dest->hizq!=0){
	    dest->hizq->padre= dest;
	  }
	  CopiarInfo(dest->hder,source->hder);
	  if (dest->hder!=0) dest->hder->padre=dest;
	  }
	  else dest=0;
}


template <class T>
void ArbolBinario<T>::BorrarInfo(ArbolBinario<T>::info_nodo *&d){
	  if (d!=0){
	   BorrarInfo(d->hizq);
	   BorrarInfo(d->hder);
	   delete d;
	  } 
  
}	  


template <class T>
unsigned int  ArbolBinario<T>::numero_nodos(const ArbolBinario<T>::info_nodo*d)const{
	  if (d==0) return 0;
	  else return 1+numero_nodos(d->hizq)+numero_nodos(d->hder);
}

template <class T>
bool  ArbolBinario<T>::iguales(const ArbolBinario<T>::info_nodo *s1,const ArbolBinario<T>::info_nodo *s2)const {
	  if (s1==0 && s2==0) return true;
	  else
	  if (s1==0 || s2==0) return false;
	  if (s1->et!=s2->et) return false;
	  else return iguales(s1->hizq,s2->hizq) && iguales(s1->hder,s2->hder);
}	  


template <class T>
void ArbolBinario<T>::InsertarHijoIzquierda(ArbolBinario<T>::info_nodo * n,
					    ArbolBinario<T>::info_nodo *  sub){
	  if (sub!=0){
	   BorrarInfo(n->hizq);
	   sub->padre=n;
	   n->hizq=sub;
          }
          else{
		    BorrarInfo(n->hizq);
		    n->hizq=0;
	  }
}	

template <class T>
void ArbolBinario<T>::InsertarHijoIzquierda(ArbolBinario<T>::info_nodo * n,
					   const T &e){
	  info_nodo *nuevo=new info_nodo(e);
	  InsertarHijoIzquierda(n,nuevo);
}


template <class T>
void ArbolBinario<T>::InsertarHijoDerecha(ArbolBinario<T>::info_nodo * n,
					   ArbolBinario<T>::info_nodo * sub){
	  if (sub!=0){
	   BorrarInfo(n->hder);
	   sub->padre=n;
	   n->hder=sub;
          }
          else{
		    BorrarInfo(n->hder);
		    n->hder=0;
	  }
}	

template <class T>
void ArbolBinario<T>::InsertarHijoDerecha(ArbolBinario<T>::info_nodo * n,
					   const T &e){
	  info_nodo *nuevo=new info_nodo(e);
	  InsertarHijoDerecha(n,nuevo);
}
template <class T> 
void ArbolBinario<T>::PodarHijoIzquierda(ArbolBinario<T>::info_nodo* n){
	  if (n->hizq!=0){
	    info_nodo * aux=n->hizq;
	    n->hizq=0;
	    BorrarInfo(aux);
	  }
}		  

template <class T> 
void ArbolBinario<T>::PodarHijoDerecha(ArbolBinario<T>::info_nodo * n){
	  if (n->hder!=0){
	    info_nodo * aux=n->hder;
	    n->hder=0;
	    BorrarInfo(aux);
	  }
}

template <class T> 
typename ArbolBinario<T>::info_nodo* ArbolBinario<T>::PodarHijoIzq_GetSubtree(ArbolBinario<T>::info_nodo * n){
	  if (n->hizq!=0){
	    typename ArbolBinario<T>::info_nodo * aux=n->hizq;
	    n->hizq=0;
	    return aux;
	   
	    
	  }
	  else  return 0;
}

template <class T> 
typename ArbolBinario<T>::info_nodo *ArbolBinario<T>::PodarHijoDer_GetSubtree(ArbolBinario<T>::info_nodo * n){
	  if (n->hder!=0){
	    typename ArbolBinario<T>::info_nodo * aux=n->hder;
	    n->hder=0;
	    return aux;
	    
	    
	  }
	  else return 0;
}


template <class T> 
void ArbolBinario<T>::RecorridoPreorden(ostream & os,const ArbolBinario<T>::info_nodo *n)const {
	if (n!=0){
		  os<<n->et;
		  RecorridoPreorden(os,n->hizq);
		  RecorridoPreorden(os,n->hder);
	}
	  
}	  

template <class T> 
void ArbolBinario<T>::RecorridoPostorden(ostream & os,const ArbolBinario<T>:: info_nodo *n)const  {
	if (n!=0){
		  
		  RecorridoPostorden(os,n->hizq);
		  RecorridoPostorden(os,n->hder);
		  os<<" "<<n->et;
	}
	  
}	


template <class T> 
void ArbolBinario<T>::RecorridoInorden(ostream & os,const ArbolBinario<T>::info_nodo *n)const {
	if (n!=0){
		  
		  RecorridoInorden(os,n->hizq);
		  os<<" "<<n->et;
		  RecorridoInorden(os,n->hder);
		  
	}	  
}	  
template <class T> 
void ArbolBinario<T>::RecorridoNiveles(ostream & os,const ArbolBinario<T>::info_nodo *n)const {
	 if (n!=0){
		   queue<const info_nodo*>Cola;
		   const info_nodo *p=n;
		   Cola.push(p);
		   while (!Cola.empty()){
			 p=Cola.front();
			 Cola.pop();
			 if (p==0){
				   os<<'_';
			 }
			 else os<<" "<<p->et;
			if (p!=0){ 
			 Cola.push(p->hizq);
			 Cola.push(p->hder);
			} 
		   }
		  
	}	  
}	  

template <class T> 
void ArbolBinario<T>::Lee(istream & is,ArbolBinario<T>::info_nodo *&n){
        char c;
	c=is.get();
        if (is){	
	
	if (c=='x') n=0;
	else{
          if (c=='n'){
		    T e;
		    is>>e;
		    
		    n= new info_nodo(e);
		    Lee(is,n->hizq);
		    Lee(is,n->hder);
		    if (n->hizq!=0)
			      n->hizq->padre=n;
		    if (n->hder!=0)
			      n->hder->padre=n;
	  }
	  
	}
     }	
}


template <class T> 
void ArbolBinario<T>::Escribe(ostream & os,const ArbolBinario<T>::info_nodo *n)const {
     
	char c;
	
	if (n==0) os<<'x';
	else{
          os<<'n'<<n->et;  
	  Escribe(os,n->hizq);
	  Escribe(os,n->hder);
	}
    	
}



/********************************************************/
/* 	FUNCIONES DE ARBOLBINARIO                       */
/********************************************************/
template <class T>
ArbolBinario<T>::ArbolBinario(typename ArbolBinario<T>::nodo n){
	  raiz=n.p;
}	  



template <class T>
ArbolBinario<T>::ArbolBinario(const T &e){
	  raiz=new info_nodo(e);
}	  

template <class T>
ArbolBinario<T>::ArbolBinario(const ArbolBinario<T> & ab){
	  if (ab.raiz==0) raiz=0;
	  else
		    CopiarInfo(raiz,ab.raiz);
}		    

template <class T>
ArbolBinario<T> & ArbolBinario<T>::operator=(const ArbolBinario<T> & ab){
	  if (this!=&ab){
		    BorrarInfo(raiz);
		    CopiarInfo(raiz,ab.raiz);
	  }
	  return (*this);
}	  
	  
template <class T>	  
typename ArbolBinario<T>::nodo ArbolBinario<T>::getRaiz()const{
	 if (raiz!=0)
	   return typename ArbolBinario<T>::nodo(raiz);
	 else 
	 return typename ArbolBinario<T>::nodo();
}	 
template <class T>	 
typename ArbolBinario<T>::nodo ArbolBinario<T>::Insertar_Hi( typename ArbolBinario<T>::nodo n,const T &e){
	  InsertarHijoIzquierda(n.p,e);
	  return typename ArbolBinario<T>::nodo(n.p->hizq);
}	  
	  
template <class T>	  
typename ArbolBinario<T>::nodo ArbolBinario<T>::Insertar_Hi( typename ArbolBinario<T>::nodo n,ArbolBinario<T> & tree){
	  
	  InsertarHijoIzquierda(n.p,tree.raiz);
	  tree.raiz=0;
	  return typename ArbolBinario<T>::nodo(n.p->hizq);
}	  
	  
template <class T>	
typename ArbolBinario<T>::nodo ArbolBinario<T>::Insertar_Hd( typename ArbolBinario<T>::nodo n ,const T &e){
	  InsertarHijoDerecha(n.p,e);
	  return typename ArbolBinario<T>::nodo(n.p->hder);
}	  
	  
template <class T>		  
typename ArbolBinario<T>::nodo ArbolBinario<T>::Insertar_Hd( typename ArbolBinario<T>::nodo n, ArbolBinario<T> & tree){
	  InsertarHijoDerecha(n.p,tree.raiz);
	  tree.raiz=0;
	  
	  return typename ArbolBinario<T>::nodo(n.p->hder);
}	  
	  
template <class T>	
void ArbolBinario<T>::Podar_Hi(typename ArbolBinario<T>::nodo pos){
	  PodarHijoIzquierda(pos.p);
}	  

template <class T>	
void ArbolBinario<T>::Podar_Hd(typename ArbolBinario<T>::nodo pos){
	  PodarHijoDerecha(pos.p);
}	  
template <class T>
ArbolBinario<T>  ArbolBinario<T>::PodarHi_GetSubtree(typename ArbolBinario<T>::nodo pos){
	  typename ArbolBinario<T>::info_nodo * aux=PodarHijoIzq_GetSubtree(pos.p);
	  if (aux!=0) aux->padre=0;
	  typename ArbolBinario<T>::nodo naux(aux);
	  ArbolBinario<T> anuevo(naux);
	  return anuevo;
}	  
template <class T>
ArbolBinario<T>  ArbolBinario<T>::PodarHd_GetSubtree(typename ArbolBinario<T>::nodo pos){
	  typename ArbolBinario<T>::info_nodo * aux=PodarHijoDer_GetSubtree(pos.p);
	  if (aux!=0)
		    aux->padre=0;
	  
	  typename ArbolBinario<T>::nodo naux(aux);
	  ArbolBinario<T> anuevo(naux);
	  return anuevo;
}

		   

template <class T>	
void ArbolBinario<T>::Sustituye_Subarbol(typename ArbolBinario<T>::nodo pos_this,const ArbolBinario<T> &a,
			      typename ArbolBinario<T>::nodo pos_a){
	  	if (this!=&a){	
				if (pos_this.p==raiz){
					BorrarInfo(pos_this.p);
					CopiarInfo(pos_this.p,pos_a.p);
					if (raiz!=0) raiz->padre=0;
				}
				else {
					info_nodo * padre = pos_this.p->padre;
				           if (padre->hizq==pos_this.p){ //si es el hijo a la izquierda
						BorrarInfo(padre->hizq);
						CopiarInfo(padre->hizq,pos_a.p);
						if (padre->hizq!=0)
						  padre->hizq->padre=padre;
					}
					else { //es el hijo a la derecha
						BorrarInfo(padre->hder);
						CopiarInfo(padre->hder,pos_a.p);
						if (padre->hder!=0)
						  padre->hder->padre=padre;
					}
				}
			}

}
template <class T>
void ArbolBinario<T>::clear(){
	  BorrarInfo(raiz);
	  raiz=0;
}	  
template <class T>
bool ArbolBinario<T>::empty()const {
	  return raiz==0;
}	  
template <class T>
unsigned int ArbolBinario<T>::size()const {
	  return numero_nodos(raiz);
}	  
template <class T>
bool ArbolBinario<T>::operator==(const ArbolBinario<T> &a)const {
	  return iguales(raiz,a.raiz);
}	  
	  
template <class T>
bool ArbolBinario<T>::operator!=(const ArbolBinario<T> &a)const{
	  return !(*this==a);
}	  
template <class T>
void ArbolBinario<T>::RecorridoPreOrden(ostream &os)const {
	  RecorridoPreorden(os,raiz);
}	  
template <class T>
void ArbolBinario<T>::RecorridoInOrden(ostream &os)const {
	  RecorridoInorden(os,raiz);
}
template <class T>
void ArbolBinario<T>::RecorridoPostOrden(ostream &os)const {
	  RecorridoPostorden(os,raiz);
}	  
template <class T>
void ArbolBinario<T>::RecorridoNiveles(ostream &os)const {
	  RecorridoNiveles(os,raiz);
}	  



/***************************PREORDEN_ITERDOR operator++**********************/
template <class T>
typename ArbolBinario<T>::preorden_iterador & ArbolBinario<T>::preorden_iterador::operator++(){
	   if (p==0)
	    return *this;
            if (p->hizq!=0) //no hemos listado aún el hijo a la izquierda
	    p = p->hizq;
            else if (p->hder!=0) //no hemos listado el hijo a la derecha
	     p = p->hder;
             else {
		  //vamos subiendo mientras seamos el hijo a la derecha
	    while (( p->padre!=0) &&
	       (p->padre->hder == p ||
	        p->padre->hder==0))
		        p=p->padre;

	    if (p->padre==0) //si es la raiz ya hemos terminado
	      p = 0;
	    else
	     p = p->padre->hder;
            }
            return *this;
	  
}



/***************************INORDEN_ITERDOR operator++**********************/
template <class T>
typename ArbolBinario<T>::inorden_iterador & ArbolBinario<T>::inorden_iterador::operator++(){
          if (p==0)
	    return *this;
          if (p->hder!=0) {
	       p= p->hder;
               while (p->hizq!=0)
                  p = p->hizq;
	  }
	  else {
	      while (p->padre!=0 &&
	         p->padre->hder == p)
	        p = p->padre;
	       // Si (padre de p es nulo), hemos terminado En caso contrario, 
		        //el siguiente a p es el padre
	      p  = p->padre;

           }
      return *this;
	  
}

/***************************POSTORDEN_ITERDOR operator++**********************/
template <class T>
typename ArbolBinario<T>::postorden_iterador & ArbolBinario<T>::postorden_iterador::operator++(){
             if (p==0)
	      return *this;
             if (p->padre==0) 
	 	     p=0;
             else{
		     if (p->padre->hizq==p){
			if (p->padre->hder!=0){
				p=p->padre->hder;
				do{
					while (p->hizq!=0) p=p->hizq;
					if (p->hder!=0) p=p->hder;
				}while(p->hizq!=0 || p->hder!=0);
			}
			else p=p->padre;
		     }
	            else p=p->padre;
	     }
               
      return *this;

	  
}	  

/**FUNCIONES BEGIN y END para los diferentes Iteradores: preorden_iterador, 
inorden_iterador y postorden_iterador*/
template <class T>
typename ArbolBinario<T>::preorden_iterador ArbolBinario<T>::beginpreorden()const {
	  typename ArbolBinario<T>::preorden_iterador nuevo(raiz);
	  return nuevo;
}	  
template <class T>
typename ArbolBinario<T>::preorden_iterador ArbolBinario<T>::endpreorden()const {
	  typename ArbolBinario<T>::preorden_iterador nuevo(0);
	  return nuevo;
}
template <class T>

typename ArbolBinario<T>::inorden_iterador ArbolBinario<T>::begininorden()const {
	    info_nodo * n = raiz;

	  if (n!=0)
		 while (n->hizq!=0)
		    n = n->hizq;
 
	  typename ArbolBinario<T>::inorden_iterador nuevo(n);
	  return nuevo;
}	  
template <class T>
typename ArbolBinario<T>::inorden_iterador ArbolBinario<T>::endinorden()const {
	 
	  typename ArbolBinario<T>::inorden_iterador nuevo(0);
	  return nuevo;
}
template <class T>
typename ArbolBinario<T>::postorden_iterador ArbolBinario<T>::beginpostorden()const {
	  info_nodo * n = raiz;

	  do {
		 while (n->hizq!=0)
		    n = n->hizq;
		 if (n->hder!=0)
		    n = n->hder;
	  } while (n->hizq!=0 || n->hder!=0);
	  
	  typename ArbolBinario<T>::postorden_iterador nuevo(n);
	  return nuevo;
}	  
template <class T>
typename ArbolBinario<T>::postorden_iterador ArbolBinario<T>::endpostorden()const {
	  typename ArbolBinario<T>::postorden_iterador nuevo(0);
	  return nuevo;
}


/************OPERACIONES DE LECTURA Y ESCRITURA***********************/
template <class T>
ostream & operator<<(ostream &os,const ArbolBinario<T> &ab){
	  ab.Escribe(os,ab.raiz);
	  return os;
}
template <class T>
istream & operator>>(istream &is,ArbolBinario<T>&ab){
	  ab.Lee(is,ab.raiz);
	  return is;
}	  












