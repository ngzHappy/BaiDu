#ifndef __TEMP__OPTIONAL__HPP0
#define __TEMP__OPTIONAL__HPP0

#include <memory>
#include <type_traits>

namespace private_{
	namespace TempOptional {

		template<typename Type>
		class NeedDestory{
		public:
			typedef Type type;
			enum   {
				value  = (true
				&& std::is_class<Type>::value
				&& (std::has_virtual_destructor<Type>::value
				|| (std::is_trivially_destructible<Type>::value == false)
				)
				)
			};
		};

		template< typename Type, std::size_t N>
		class NeedDestory< Type[N] >{
		public:
			typedef Type type[N];
			enum  {
				value = (NeedDestory<Type>::value)
			};
		};

		template< typename Type >
		class NeedDestory< Type[] >{
		public:
			typedef Type type[] ;
			enum  {
				value = (NeedDestory<Type>::value)
			};
		};

	}
}
template<
	typename TypeName, 
	bool NeedDestory = private_::TempOptional::NeedDestory<TypeName>::value
>
class TempOptional{
public:

	typedef TypeName type;

	TempOptional(){}
	~TempOptional(){ destory(); }

	template<typename ... Args >
	void emplace( Args && ... args ){
		destory();
		dataPointer = new(get()) type( std::forward<Args>(args)... );
	}

	type * operator->(){ return get(); }
	const type * operator->()const{ return get(); }

	type & operator*(){ return *get(); }
	const type & operator*()const{ return *get(); }

	explicit operator bool()const { return dataPointer != nullptr; }

	TempOptional(const TempOptional &)=delete;
	TempOptional(TempOptional &&) = delete;

	TempOptional&operator=(const TempOptional &) = delete;
	TempOptional&operator=(TempOptional &&) = delete;

private:
	typedef typename std::aligned_storage< sizeof(type), std::alignment_of<type>::value > DataType;
	typename DataType::type data;
	type * dataPointer = nullptr;
private:
	const type * get() const { return reinterpret_cast<const type *>(&(data)); }
	type * get() { return reinterpret_cast<type *>(&(data)); }
	void destory(){ if (dataPointer){ dataPointer->~type(); } }
};

template<typename TypeName  >
class TempOptional< TypeName,false >{
public:

	typedef TypeName type;

	TempOptional() {    }

	template<typename ... Args >
	void emplace(Args && ... args){
		dataPointer = new(get()) type(std::forward<Args>(args)...);
	}

	type * operator->(){ return get(); }
	const type * operator->()const{ return get(); }

	type & operator*(){ return *get(); }
	const type & operator*()const{ return *get(); }

	explicit operator bool()const { return dataPointer!=nullptr; }

	TempOptional(const TempOptional &) = delete;
	TempOptional(TempOptional &&) = delete;

	TempOptional&operator=(const TempOptional &) = delete;
	TempOptional&operator=(TempOptional &&) = delete;

private:
	typedef typename std::aligned_storage< sizeof(type), std::alignment_of<type>::value > DataType;
	typename DataType::type data;
	type * dataPointer = nullptr;
private:
	const type * get() const { return reinterpret_cast<const type *>( &( data) ); }
	type * get() { return reinterpret_cast<type *>(&( data)); }
};

#endif
