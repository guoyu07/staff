/*
 *  Copyright 2009 Utkin Dmitry
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
 
/* 
 *  This file is part of the WSF Staff project.
 *  Please, visit http://code.google.com/p/staff for more information.
 */

#ifndef _SHAREDPTRCOUNT_H_
#define _SHAREDPTRCOUNT_H_

#include <rise/threading/AtomicCount.h>

namespace rise
{
  //!  "Умный" потоковобезопасный указатель на обьект, поддерживающий счет
  template<class Type>
  class CSharedPtrCount
  {
  public:
    //! конструктор
    /*
       std::bad_alloc
       \param  pContainer - указатель на обьект
    */
    CSharedPtrCount(Type* pObject);

    //! конструктор
    CSharedPtrCount(const CSharedPtrCount& rSharedPtrCount);

    //! деструктор
    ~CSharedPtrCount();

    //!        получение ссылки на обьект
    /*
        CLogicNoInitException - обьект не проинициализирован
       \return указатель на обьект
    */
    Type& operator*() throw();

    //!        оператор разыменовывания
    /*
       CLogicNoInitException - обьект не проинициализирован
       \return указатель на обьект
    */
    Type* operator->() throw();

    //!        оператор разыменовывания
    /*
       CLogicNoInitException - обьект не проинициализирован
       \return указатель на обьект
    */
    const Type* operator->() const throw();

    //!        получение ссылки на контролируемый обьект
    /*
       \return ссылка на контролируемый объект
    */
    operator Type&();

    //!        получение константной ссылки на контролируемый обьект
    /*
       \return константная ссылка на контролируемый объект
    */
    operator const Type&() const;

    //!        получение указателя на объект
    /*
       \return указатель на объект
    */
    Type* GetPointer() throw();
    
    //!        получение указателя на объект
    /*
       \return указатель на объект
    */
    Type* GetPointer() const throw();
    
    //!        получение количества ссылок
    /*
       \return количество ссылок
    */
    long GetRefCount() const throw();
    
    //!        уникален ли объект
    /*
       \return true, если объект уникален(количество ссылок = 1)
    */
    bool IsUnique() const;
    
    //!        обмен указателей на объект
    /*
       \param  rOther - ссылка на другой объект
    */
    void Swap(CSharedPtrCount<Type>& rOther);

  private:
    Type* m_pObject;         //! указатель на обьект
  };

  //!        один обьект пренадлежит двум контейнерам?
  /*
     \param  ссылки на объекты
     \return true, если если оба контейнера содержат один обьект
  */
  template<class TypeLeft, class TypeRight>
  bool operator==(const CSharedPtrCount<TypeLeft>& rLeft, const CSharedPtrCount<TypeRight>& rRight) throw();
  
  //!        разные ли обьект пренадлежит двум контейнерам?
  /*
     \param  ссылки на объекты
     \return true, если если контейнеры содержат разные обьект
  */
  template<class TypeLeft, class TypeRight>
  bool operator!=(const CSharedPtrCount<TypeLeft>& rLeft, const CSharedPtrCount<TypeRight>& rRight) throw();

  //!        оператор меньше
  /*
     \param  ссылки на объекты
     \return true, если если левый операнд меньше правого
  */
  template<class Type>
  bool operator<(const CSharedPtrCount<Type>& rLeft, const CSharedPtrCount<Type>& rRight) throw();
  
  //!        оператор больше
  /*
     \param  ссылки на объекты
     \return true, если если левый операнд больше правого
  */
  template<class Type>
  bool operator>(const CSharedPtrCount<Type>& rLeft, const CSharedPtrCount<Type>& rRight) throw();

} // namespace rise

#include "SharedPtrCount.hpp"

#endif // _SHAREDPTRCOUNT_H_
