#ifndef _ARBOLBINARIO__
#define _ARBOLBINARIO__
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
/**
  TDA ArbolBinario
  @doc Definición : Una instancia \a a del tipo de dato abstracto ArbolBinario sobre un
  dominio T se puede construir como:
	  - Un objeto vacío si no contiene ningun elemento
	  - Un arbol que contiene un elemento destacad la raíz con un valor e en el dominio T
	     denominado etiqueta y dos subarboles (Ti:subarbol izquierdo, y Td:subarbol derecho) del
	     T.D.A Arbolbinario sobre T. Se establece una relación padre-hijo entre cada nodo y los
	     nodos raíz de los subarboles ( si existen) que cuelgan de el. Lo denotamos como 
	     {e,{Ti},{Td}}
	  Para poder usar el TDA ArbolBinario se debe incluir ArbolBinario.h
	  Son mutables. El espacio requerido para el almacenamiento es O(n) siendo n el numero de nodos.
*/

template <class T>
class ArbolBinario{
	  private:
	  struct info_nodo{
		    T et;
		    info_nodo * padre;
		    info_nodo * hizq;
		    info_nodo * hder;
		    info_nodo(){ padre=hizq=hder=0; }
		    info_nodo(const T & e){ et = e; padre=hizq=hder=0;}
	 };
	  //Funciones asociadas a info_nodo	
	  /**
	    @brief Copiar un subarbol en otro
	    @param dest: objeto donde queda la copia. ES MODIFICADO
	    @param source: objeto desde el que se copia.
	  */
	  
	  void CopiarInfo(info_nodo * &dest,const info_nodo*const &source);
	  /** 
	    @brief Borra toda la información asociada a un subarbol  
	    @param d: raiz del subarbol a borrar. ES MODIFICADO
	  */
	  
	  void BorrarInfo(info_nodo *&d);
	  
	  /**
	    @brief Devuelve el numero de nodos del subarbol
	    @param d: raiz del subarbol
	  */
	  unsigned int numero_nodos(const info_nodo*d)const ;
	  
	  
	  /**
	    @brief Devuelve true si los dos subarboles son iguales
	    @param s1: raiz del primer subarbol
	    @param s2: raiz del segundo subarbol
	    @note : el tipo T debe tener definido el operador ==
	  */
	  bool iguales(const info_nodo*s1,const info_nodo*s2)const ;
	  
	  /**
	    @brief. Inserta un subarbol como hijo a la izquierda de uno dado
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la izquierda.
            @param sub: raiz del subarbol que se inserta 	
            @note el subarbol hijo a la izquierda de n es eliminado
           */
	  void InsertarHijoIzquierda(info_nodo * n,info_nodo * sub);
	  /**
	    @brief. Inserta un subarbol como hijo a la izquierda de uno dado que consta de un solo nodo
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la izquierda.
            @param e: etiqueta de la raiz del subarbol que se inserta
            @note el subarbol hijo a la izquierda de n es eliminado
           */
	  
	  void InsertarHijoIzquierda(info_nodo * n,const T & e);
	  
	  /**
	    @brief. Inserta un subarbol como hijo a la derecha de uno dado
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la derecha.
            @param sub: raiz del subarbol que se inserta 	
            @note el subarbol hijo a la derecha de n es eliminado
           */
	  void InsertarHijoDerecha(info_nodo * n, info_nodo * sub);
	  
	  /**
	    @brief. Inserta un subarbol como hijo a la derecha de uno dado que consta de un solo nodo
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la derecha.
            @param e: etiqueta de la raiz del subarbol que se inserta
            @note el subarbol hijo a la derecha de n es eliminado
           */
	  void InsertarHijoDerecha(info_nodo * n,const T & e);
	  /**
	    @brief Elimina el hijo a la izquierda del subarbol dado
	    @param n: subarbol al que se le poda el hijo a la izquierda.
	    @note: el hijo a la izquierda es puesto a nulo tras la ejecucion
	  */
	  void PodarHijoIzquierda(info_nodo * n);
	  /**
	    @brief Elimina el hijo a la derecha del subarbol dado
	    @param n: subarbol al que se le poda el hijo a la derecha.
	    @note: el hijo a la derecha es puesto a nulo tras la ejecucion
	  */
	  void PodarHijoDerecha(info_nodo * n);
	  /**
	    @brief Elimina el hijo a la izquierda del subarbol sin borrarlo
	    @param n: subarbol al que se le poda el hijo a la derecha.
	    @return: el subarbol hijo a la izquierda
	  */
	  info_nodo *PodarHijoIzq_GetSubtree(info_nodo * n);
	  
	  /**
	    @brief Elimina el hijo a la derecha del subarbol sin borrarlo
	    @param n: subarbol al que se le poda el hijo a la derecha.
	    @return: el subarbol hijo a la derecha
	  */
	  info_nodo *PodarHijoDer_GetSubtree(info_nodo * n);
	  
	  /**
	    @brief Obtiene en un flujo de salida el recorrido Preorden del subarbol
	    @param os: flujo de salida.ES MODIFICADO
	    @param n: subarbol sobre el que se obtiene el recorrido en preorden
	    
	  */
	  void RecorridoPreorden(ostream & os, const info_nodo *n)const ;
	  /**
	    @brief Obtiene en un flujo de salida el recorrido PostOrden del subarbol
	    @param os: flujo de salida.ES MODIFICADO
	    @param n: subarbol sobre el que se obtiene el recorrido en postorden
	    
	  */
	  void RecorridoPostorden(ostream & os,const info_nodo *n)const ;
	  /**
	    @brief Obtiene en un flujo de salida el recorrido inorden del subarbol
	    @param os: flujo de salida.ES MODIFICADO
	    @param n: subarbol sobre el que se obtiene el recorrido en inorden
	    
	  */
	  void RecorridoInorden(ostream & os,const info_nodo *n)const ;
	  /**
	    @brief Escribe en un flujo de salida del subarbol por niveles
	    @param os: flujo de salida. ES MODIFICADO
	    @param n: subarbol sobre el que se obtiene el recorrido por niveles
	    @note: si un nodo es nulo se pone _
	  */  
          void RecorridoNiveles(ostream &os,const info_nodo *n)const ;	  
	   /**
	    @brief Lee un subarbol del flujo
	    @param is: flujo de entrada.
	    @param n: subarbol que se lee. ES MODIFICADO
	    @note si no existe el nodo aparece una x si existe una n
	   */
	  void Lee(istream & is, info_nodo *&n);
	  /**
	    @brief Escribe un subarbol en el flujo
	    @param is: flujo de salida
	    @param n: subarbol que se escribe. 
	    @note si no existe el nodo aparece una x si existe una n
	   */
	  void Escribe(ostream & os,const  info_nodo *n)const;
	  
	 
	  
	  
	  
	  info_nodo * raiz;
 	  public:
		    
		    //declaración adelantada del tipo nodo (posicionamiento en un arbolbinario)
		    class nodo;
		    class preorden_iterador;
		    class inorden_iterador;
		    class postorden_iterador;
		    /**
			 @brief Constructor por defecto
		    */
		    ArbolBinario():raiz(0){}
		    
		    /**
		      @brief Constructor con parametros
		    */
		    
		    
		    ArbolBinario(const T &e);
		    ArbolBinario(typename ArbolBinario<T>::nodo n);
		    /**
		      @brief Constructor por copia
		    */
		    ArbolBinario(const ArbolBinario<T> & ab);
		    
		    /**
		      @brief Destructor
		     */
		    ~ArbolBinario(){ clear();}
		    /**
		      @brief Operador de asignacion
		      @param ab: arbol binario del que se copia
		    */
		    ArbolBinario<T> & operator=(const ArbolBinario<T> & ab);
		    
		    /**
		      @brief Obtiene un nodo apuntando a la raiz del arbol
		     */
		      
		    typename ArbolBinario<T>::nodo getRaiz()const;
		    /**
		      @brief Inserta un subarbol como hijo izquierdo del nodo. Este suabarbol solamente tiene un nodo
		      @param n: posicion del nodo donde insertar el subarbol como hijo izquierdo
		      @param e: etiqueta de la raiz del subarbol que se inserta
		    */
		    typename ArbolBinario<T>::nodo Insertar_Hi( typename ArbolBinario<T>::nodo n,const T &e);
		    /**
		      @brief Inserta un subarbol como hijo izquierdo del nodo.
		      @param n: posicion del nodo donde insertar el subarbol como hijo izquierdo
		      @param tree:subarbol que se inserta. ES MODIFICADO
		    */
		    
		    typename ArbolBinario<T>::nodo Insertar_Hi( typename ArbolBinario<T>::nodo n ,ArbolBinario<T> & tree);
		    
		    /**
		      @brief Inserta un subarbol como hijo derecho del nodo. Este suabarbol solamente tiene un nodo
		      @param n: posicion del nodo donde insertar el subarbol como hijo derecho
		      @param e: etiqueta de la raiz del subarbol que se inserta
		    */
		    typename ArbolBinario<T>::nodo Insertar_Hd( typename ArbolBinario<T>::nodo n,const T &e);
		    
		    /**
		      @brief Inserta un subarbol como hijo derecho del nodo. 
		      @param n: posicion del nodo donde insertar el subarbol como hijo derecho
		      @param tree:  subarbol que se inserta. ES MODIFICADO
		    */
		    typename ArbolBinario<T>::nodo Insertar_Hd( typename ArbolBinario<T>::nodo n,ArbolBinario<T> & tree);
		    
		    
		    /**
		      @brief Poda el hijo izquierdo del nodo dado
		      @pos: posicion del nodo
		    */  
		    void Podar_Hi(typename ArbolBinario<T>::nodo pos);
		    
		    /**
		      @brief Poda el hijo derecho del nodo dado
		      @pos: posicion del nodo
		    */  
		    
		    void Podar_Hd(typename ArbolBinario<T>::nodo pos);
		    
		    /**
		      @brief Poda el hijo derecho o izquierda del nodo del nodo dado
		      @pos: posicion del nodo
		      @return un arbol nuevo con esta rama eliminada
		    */  
		   ArbolBinario<T>  PodarHi_GetSubtree(typename ArbolBinario<T>::nodo pos); 
		   ArbolBinario<T>  PodarHd_GetSubtree(typename ArbolBinario<T>::nodo pos);
		     
		    /**
		     @brief Se sustituye el subarbol por otro subarbol de otro arbol
		     @param pos_this: posicion de la raiz del subarbol a ser copiado. El que hubiese previo se elimina.
		     @param a: arbol fuente.
		     @param pos_a: posicion de la raiz del suarbol de \a  a que va a ser copiado.
		    */ 
		    void Sustituye_Subarbol(typename ArbolBinario<T>::nodo pos_this,const ArbolBinario<T> &a,
					    typename ArbolBinario<T>::nodo pos_a);
		  
		   /**
		     @brief Borra todo arbol, dejandolo como un arbol vacio
		    */
		    void clear();
		    
		    /**
		      @brief Arbol vacio
		      @return Devuelve si el arbol es vacio (true), y falso en caso contrario
		    */
		    bool empty()const ;
		    
		    /**
		      @brief Tamaño de un arbol
		      @return Devuelve  el numero de nodos que tiene el arbol
		      
		    */  
		    unsigned int size()const ;
		    
		    /**
		      @brief Igualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son iguales false en caso contrario
		    */  
		    bool operator==(const ArbolBinario<T> &a)const;
		    
		    /**
		      @brief Desigualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son distintos false en caso contrario
		    */
		    bool operator!=(const ArbolBinario<T> &a)const;
		    
		    
		    /**
		      @brief Recorrido en Preorden
		      @param os: flujo sobre el que se da el recorrido del arbol en preorden
		     */
		    void RecorridoPreOrden(ostream &os)const ;
		    /**
		      @brief Recorrido en Inorden
		      @param os: flujo sobre el que se da el recorrido del arbol en Inorden
		     */
		    void RecorridoInOrden(ostream &os)const ;
		    /**
		      @brief Recorrido en Postorden
		      @param os: flujo sobre el que se da el recorrido del arbol en Postorden
		     */
		    
		    void RecorridoPostOrden(ostream &os)const ;
		    /**
		      @brief Recorrido por niveles
		      @param os: flujo sobre el que se da el recorrido del arbol por niveles
		     */
		    void RecorridoNiveles(ostream &os)const ;
		    
		    
		    
		    
		    
		    
		    /*ITERADORES:					  */ 
		    /******************************************************/
		    /*                   CLASE NODO			  */
		    /******************************************************/
		    class nodo{
			      private:
			         info_nodo *p;
				  /**
				  @brief Constructo con parametros
				  @param i: nodo que se copia
				  */
			         nodo (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         nodo ():p(0){}
			        
			         /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */  
			         nodo (const nodo &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */  
			         const T& operator*()const { 
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() { 
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */ 
				 bool operator==(const nodo &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const nodo &n){
					   return p!=n.p;
				 }	
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */   
				 nodo padre(){
					   if (p->padre!=0)
					    return nodo(p->padre);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */   
				 nodo hi(){
					   if (p->hizq!=0)
					    return nodo(p->hizq);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */   
				 nodo hd(){
					   if (p->hder!=0)
					    return nodo(p->hder);
					   else return nodo();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */   
				 bool nulo(){
					   return p==0;
				 }
				 friend class ArbolBinario;
				 friend class preorden_iterador;
				 friend class inorden_iterador;
				 friend class postorden_iterador;
				 
		    };		 
		    
		     /******************************************************/
		    /*                   CLASE PREORDEN_ITERADOR		  */
		    /******************************************************/
		    class preorden_iterador{
			      private:
			         info_nodo *p;
				   /**
				  @brief Constructo con parametros
				  @param i: nodo que se copia
				  */
			         preorden_iterador (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         preorden_iterador ():p(0){}
			       
			         /**
				   @brief Constructor con nodo
				   @param n: nodo fuente
				 */  
			         preorden_iterador (const nodo &n):p(n.p){}
			          /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */  
			         preorden_iterador (const preorden_iterador &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */  
			         const T& operator*()const { 
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() { 
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */ 
				 bool operator==(const preorden_iterador &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const preorden_iterador &n){
					   return p!=n.p;
				 }	
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */   
				 preorden_iterador padre(){
					   if (p->padre!=0)
					    return preorden_iterador(p->padre);
					   else return preorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */   
				 preorden_iterador hi(){
					   if (p->hizq!=0)
					    return preorden_iterador(p->hizq);
					   else return preorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */   
				 preorden_iterador hd(){
					   if (p->hder!=0)
					    return preorden_iterador(p->hder);
					   else return preorden_iterador();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */   
				 bool nulo(){
					   return p==0;
				 }
				 preorden_iterador &operator++();
				 
				 friend class ArbolBinario;
				 
				 
		    };		 
		    
		      /******************************************************/
		     /*                   CLASE INORDEN_ITERADOR		     */
		    /*********************************************************/
		    class inorden_iterador{
			      private:
			         info_nodo *p;
				   /**
				  @brief Constructor con parametros
				  @param i: nodo que se copia
				  */
			         inorden_iterador (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         inorden_iterador ():p(0){}
			       
			         /**
				   @brief Constructor con nodo
				   @param n: nodo fuente
				 */  
			         inorden_iterador (const nodo &n):p(n.p){}
			          /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */  
			         inorden_iterador (const inorden_iterador &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */  
			         const T& operator*()const { 
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() { 
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */ 
				 bool operator==(const inorden_iterador &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const inorden_iterador &n){
					   return p!=n.p;
				 }	
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */   
				 inorden_iterador padre(){
					   if (p->padre!=0)
					    return inorden_iterador(p->padre);
					   else return inorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */   
				 inorden_iterador hi(){
					   if (p->hizq!=0)
					    return inorden_iterador(p->hizq);
					   else return inorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */   
				 inorden_iterador hd(){
					   if (p->hder!=0)
					    return inorden_iterador(p->hder);
					   else return inorden_iterador();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */   
				 bool nulo(){
					   return p==0;
				 }
				 inorden_iterador &operator++();
				 
				 friend class ArbolBinario;
				 
				 
		    };		 
		    
		      /******************************************************/
		     /*                   CLASE POSTORDEN_ITERADOR		     */
		    /*********************************************************/
		    class postorden_iterador{
			      private:
			         info_nodo *p;
				   /**
				  @brief Constructor con parametros
				  @param i: nodo que se copia
				  */
			         postorden_iterador (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         postorden_iterador ():p(0){}
			       
			         /**
				   @brief Constructor con nodo
				   @param n: nodo fuente
				 */  
			         postorden_iterador (const nodo &n):p(n.p){}
			          /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */  
			         postorden_iterador (const postorden_iterador &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */  
			         const T& operator*()const { 
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() { 
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */ 
				 bool operator==(const postorden_iterador &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const postorden_iterador &n){
					   return p!=n.p;
				 }	
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */   
				 postorden_iterador padre(){
					   if (p->padre!=0)
					    return postorden_iterador(p->padre);
					   else return postorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */   
				 postorden_iterador hi(){
					   if (p->hizq!=0)
					    return postorden_iterador(p->hizq);
					   else return postorden_iterador();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */   
				 postorden_iterador hd(){
					   if (p->hder!=0)
					    return postorden_iterador(p->hder);
					   else return postorden_iterador();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */   
				 bool nulo(){
					   return p==0;
				 }
				postorden_iterador &operator++();
				 
				 friend class ArbolBinario;
				 
				 
		    };		 
		    /***FUNCIONES BEGIN y EN PARA PREORDEN_ITERATOR***/
		    /**
		     @brief Comienzo de un iterador preorden_iterador
		     @return un iterador de tipo preorden apuntando a la raiz
		    */
		    preorden_iterador beginpreorden()const ;
		    /**
		     @brief Final de un iterador preorden_iterador
		     @return un iterador de tipo preorden apuntando al final
		    */
		    preorden_iterador endpreorden()const;
		    
		    /***FUNCIONES BEGIN y EN PARA INORDEN_ITERATOR***/
		    /**
		     @brief Comienzo de un iterador inorden_iterador
		     @return un iterador de tipo inorden apuntando a la raiz
		    */
		    inorden_iterador begininorden()const;
		    /**
		     @brief Final de un iterador inorden_iterador
		     @return un iterador de tipo inorden apuntando al final
		    */
		    inorden_iterador endinorden()const ;
		    
		    /***FUNCIONES BEGIN y EN PARA INORDEN_ITERATOR***/
		    /**
		     @brief Comienzo de un iterador postorden_iterador
		     @return un iterador de tipo postorden apuntando a la raiz
		    */
		    postorden_iterador beginpostorden()const ;
		    /**
		     @brief Final de un iterador postorden_iterador
		     @return un iterador de tipo postorden apuntando al final
		    */
		    postorden_iterador endpostorden()const;
		    
		    	      
		    
		    
		      /** 
		      @brief  Escritura de un arbol binario
		      @param os: flujo de salida
		      @param ab: arbol binario que se escribe
		    */  
		     template <class U> 
		    friend ostream & operator<<(ostream &os,const ArbolBinario<U> &ab);
		     		    
		    /** 
		      @brief  Lectura  de un arbol binario
		      @param os: flujo de entrada
		      @param ab: arbol binario sobre el que se lee
		    */
		    template <class U>
		    friend istream & operator>>(istream &is,ArbolBinario<U> &ab);
		    

		    
};
#include "arbolbinario.tpp"
#endif