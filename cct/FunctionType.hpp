#if !defined(FUNCTION_TYPE__CCT)
#define FUNCTION_TYPE__CCT

#include <functional>

namespace cct {

template<typename T  >
class FunctionType {
};

template<
    typename ReturnType
>
class FunctionType< ReturnType() > {
public:
    typedef ReturnType return_type;
    typedef void _0;
    typedef void _r0;
    typedef ReturnType(*function_type)();
    typedef std::function< ReturnType() > stl_function_type;
    typedef ReturnType(std_function_type)();
    enum { arg_size=1 };
};

//std function surport
template<
    typename ReturnType
>
class FunctionType< std::function< ReturnType() > >
    :public FunctionType< ReturnType() > {
public:
    typedef std::function<ReturnType()> stl_function_type;
};

template<
    typename ReturnType
>
class FunctionType< ReturnType(*)() > {
public:
    typedef ReturnType return_type;
    typedef void _0;
    typedef void _r0;
    typedef ReturnType(*function_type)();
    typedef ReturnType(std_function_type)();
    typedef std::function<ReturnType()> stl_function_type;
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename ClassType
>
class FunctionType< ReturnType(ClassType::*)() > {
public:
    typedef ReturnType return_type;
    typedef void _0;
    typedef void _r0;
    typedef ReturnType(ClassType::* function_type)();
    typedef std::function<ReturnType(ClassType *)> stl_function_type;
    typedef ReturnType(std_function_type)(ClassType *);
    typedef ClassType class_type;
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename ClassType
>
class FunctionType< ReturnType(ClassType::*)() const > {
public:
    typedef ReturnType return_type;
    typedef void _0;
    typedef void _r0;
    typedef ReturnType(ClassType::* function_type)() const;
    typedef std::function<ReturnType(const ClassType *)> stl_function_type;
    typedef ReturnType(std_function_type)(const ClassType *);
    typedef ClassType class_type;
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename Arg0
>
class FunctionType< ReturnType(
    Arg0) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg0 _r0;
    typedef ReturnType(*function_type)(
        Arg0);
    typedef std::function< ReturnType(
        Arg0) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0);
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename Arg0
>
class FunctionType< std::function< ReturnType(
    Arg0) > > : public FunctionType< ReturnType(
        Arg0) > {
public:
};

template<
    typename ReturnType,
    typename Arg0
>
class FunctionType< ReturnType(*)(
    Arg0) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg0 _r0;
    typedef ReturnType(*function_type)(
        Arg0);
    typedef std::function< ReturnType(
        Arg0) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0);
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg0 _r0;
    typedef ReturnType(ClassType::* function_type)(
        Arg0);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0);
    typedef ClassType class_type;
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg0 _r0;
    typedef ReturnType(ClassType::* function_type)(
        Arg0) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0);
    typedef ClassType class_type;
    enum { arg_size=1 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1
>
class FunctionType< ReturnType(
    Arg0,
    Arg1) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg1 _r0;
    typedef Arg0 _r1;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1);
    typedef std::function< ReturnType(
        Arg0,
        Arg1) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1);
    enum { arg_size=2 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg1 _r0;
    typedef Arg0 _r1;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1);
    typedef std::function< ReturnType(
        Arg0,
        Arg1) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1);
    enum { arg_size=2 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg1 _r0;
    typedef Arg0 _r1;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1);
    typedef ClassType class_type;
    enum { arg_size=2 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg1 _r0;
    typedef Arg0 _r1;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1);
    typedef ClassType class_type;
    enum { arg_size=2 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg2 _r0;
    typedef Arg1 _r1;
    typedef Arg0 _r2;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2);
    enum { arg_size=3 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg2 _r0;
    typedef Arg1 _r1;
    typedef Arg0 _r2;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2);
    enum { arg_size=3 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg2 _r0;
    typedef Arg1 _r1;
    typedef Arg0 _r2;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2);
    typedef ClassType class_type;
    enum { arg_size=3 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg2 _r0;
    typedef Arg1 _r1;
    typedef Arg0 _r2;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2);
    typedef ClassType class_type;
    enum { arg_size=3 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg3 _r0;
    typedef Arg2 _r1;
    typedef Arg1 _r2;
    typedef Arg0 _r3;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    enum { arg_size=4 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg3 _r0;
    typedef Arg2 _r1;
    typedef Arg1 _r2;
    typedef Arg0 _r3;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    enum { arg_size=4 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg3 _r0;
    typedef Arg2 _r1;
    typedef Arg1 _r2;
    typedef Arg0 _r3;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    typedef ClassType class_type;
    enum { arg_size=4 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg3 _r0;
    typedef Arg2 _r1;
    typedef Arg1 _r2;
    typedef Arg0 _r3;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3);
    typedef ClassType class_type;
    enum { arg_size=4 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg4 _r0;
    typedef Arg3 _r1;
    typedef Arg2 _r2;
    typedef Arg1 _r3;
    typedef Arg0 _r4;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    enum { arg_size=5 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg4 _r0;
    typedef Arg3 _r1;
    typedef Arg2 _r2;
    typedef Arg1 _r3;
    typedef Arg0 _r4;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    enum { arg_size=5 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg4 _r0;
    typedef Arg3 _r1;
    typedef Arg2 _r2;
    typedef Arg1 _r3;
    typedef Arg0 _r4;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    typedef ClassType class_type;
    enum { arg_size=5 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg4 _r0;
    typedef Arg3 _r1;
    typedef Arg2 _r2;
    typedef Arg1 _r3;
    typedef Arg0 _r4;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4);
    typedef ClassType class_type;
    enum { arg_size=5 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg5 _r0;
    typedef Arg4 _r1;
    typedef Arg3 _r2;
    typedef Arg2 _r3;
    typedef Arg1 _r4;
    typedef Arg0 _r5;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    enum { arg_size=6 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg5 _r0;
    typedef Arg4 _r1;
    typedef Arg3 _r2;
    typedef Arg2 _r3;
    typedef Arg1 _r4;
    typedef Arg0 _r5;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    enum { arg_size=6 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg5 _r0;
    typedef Arg4 _r1;
    typedef Arg3 _r2;
    typedef Arg2 _r3;
    typedef Arg1 _r4;
    typedef Arg0 _r5;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    typedef ClassType class_type;
    enum { arg_size=6 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg5 _r0;
    typedef Arg4 _r1;
    typedef Arg3 _r2;
    typedef Arg2 _r3;
    typedef Arg1 _r4;
    typedef Arg0 _r5;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5);
    typedef ClassType class_type;
    enum { arg_size=6 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg6 _r0;
    typedef Arg5 _r1;
    typedef Arg4 _r2;
    typedef Arg3 _r3;
    typedef Arg2 _r4;
    typedef Arg1 _r5;
    typedef Arg0 _r6;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    enum { arg_size=7 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg6 _r0;
    typedef Arg5 _r1;
    typedef Arg4 _r2;
    typedef Arg3 _r3;
    typedef Arg2 _r4;
    typedef Arg1 _r5;
    typedef Arg0 _r6;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    enum { arg_size=7 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg6 _r0;
    typedef Arg5 _r1;
    typedef Arg4 _r2;
    typedef Arg3 _r3;
    typedef Arg2 _r4;
    typedef Arg1 _r5;
    typedef Arg0 _r6;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    typedef ClassType class_type;
    enum { arg_size=7 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg6 _r0;
    typedef Arg5 _r1;
    typedef Arg4 _r2;
    typedef Arg3 _r3;
    typedef Arg2 _r4;
    typedef Arg1 _r5;
    typedef Arg0 _r6;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6);
    typedef ClassType class_type;
    enum { arg_size=7 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg7 _r0;
    typedef Arg6 _r1;
    typedef Arg5 _r2;
    typedef Arg4 _r3;
    typedef Arg3 _r4;
    typedef Arg2 _r5;
    typedef Arg1 _r6;
    typedef Arg0 _r7;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    enum { arg_size=8 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg7 _r0;
    typedef Arg6 _r1;
    typedef Arg5 _r2;
    typedef Arg4 _r3;
    typedef Arg3 _r4;
    typedef Arg2 _r5;
    typedef Arg1 _r6;
    typedef Arg0 _r7;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    enum { arg_size=8 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg7 _r0;
    typedef Arg6 _r1;
    typedef Arg5 _r2;
    typedef Arg4 _r3;
    typedef Arg3 _r4;
    typedef Arg2 _r5;
    typedef Arg1 _r6;
    typedef Arg0 _r7;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    typedef ClassType class_type;
    enum { arg_size=8 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg7 _r0;
    typedef Arg6 _r1;
    typedef Arg5 _r2;
    typedef Arg4 _r3;
    typedef Arg3 _r4;
    typedef Arg2 _r5;
    typedef Arg1 _r6;
    typedef Arg0 _r7;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7);
    typedef ClassType class_type;
    enum { arg_size=8 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg8 _r0;
    typedef Arg7 _r1;
    typedef Arg6 _r2;
    typedef Arg5 _r3;
    typedef Arg4 _r4;
    typedef Arg3 _r5;
    typedef Arg2 _r6;
    typedef Arg1 _r7;
    typedef Arg0 _r8;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    enum { arg_size=9 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg8 _r0;
    typedef Arg7 _r1;
    typedef Arg6 _r2;
    typedef Arg5 _r3;
    typedef Arg4 _r4;
    typedef Arg3 _r5;
    typedef Arg2 _r6;
    typedef Arg1 _r7;
    typedef Arg0 _r8;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    enum { arg_size=9 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg8 _r0;
    typedef Arg7 _r1;
    typedef Arg6 _r2;
    typedef Arg5 _r3;
    typedef Arg4 _r4;
    typedef Arg3 _r5;
    typedef Arg2 _r6;
    typedef Arg1 _r7;
    typedef Arg0 _r8;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    typedef ClassType class_type;
    enum { arg_size=9 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg8 _r0;
    typedef Arg7 _r1;
    typedef Arg6 _r2;
    typedef Arg5 _r3;
    typedef Arg4 _r4;
    typedef Arg3 _r5;
    typedef Arg2 _r6;
    typedef Arg1 _r7;
    typedef Arg0 _r8;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8);
    typedef ClassType class_type;
    enum { arg_size=9 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg9 _r0;
    typedef Arg8 _r1;
    typedef Arg7 _r2;
    typedef Arg6 _r3;
    typedef Arg5 _r4;
    typedef Arg4 _r5;
    typedef Arg3 _r6;
    typedef Arg2 _r7;
    typedef Arg1 _r8;
    typedef Arg0 _r9;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    enum { arg_size=10 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9) > {
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg9 _r0;
    typedef Arg8 _r1;
    typedef Arg7 _r2;
    typedef Arg6 _r3;
    typedef Arg5 _r4;
    typedef Arg4 _r5;
    typedef Arg3 _r6;
    typedef Arg2 _r7;
    typedef Arg1 _r8;
    typedef Arg0 _r9;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    enum { arg_size=10 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg9 _r0;
    typedef Arg8 _r1;
    typedef Arg7 _r2;
    typedef Arg6 _r3;
    typedef Arg5 _r4;
    typedef Arg4 _r5;
    typedef Arg3 _r6;
    typedef Arg2 _r7;
    typedef Arg1 _r8;
    typedef Arg0 _r9;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    typedef ClassType class_type;
    enum { arg_size=10 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg9 _r0;
    typedef Arg8 _r1;
    typedef Arg7 _r2;
    typedef Arg6 _r3;
    typedef Arg5 _r4;
    typedef Arg4 _r5;
    typedef Arg3 _r6;
    typedef Arg2 _r7;
    typedef Arg1 _r8;
    typedef Arg0 _r9;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9);
    typedef ClassType class_type;
    enum { arg_size=10 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg10 _r0;
    typedef Arg9 _r1;
    typedef Arg8 _r2;
    typedef Arg7 _r3;
    typedef Arg6 _r4;
    typedef Arg5 _r5;
    typedef Arg4 _r6;
    typedef Arg3 _r7;
    typedef Arg2 _r8;
    typedef Arg1 _r9;
    typedef Arg0 _r10;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    enum { arg_size=11 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg10 _r0;
    typedef Arg9 _r1;
    typedef Arg8 _r2;
    typedef Arg7 _r3;
    typedef Arg6 _r4;
    typedef Arg5 _r5;
    typedef Arg4 _r6;
    typedef Arg3 _r7;
    typedef Arg2 _r8;
    typedef Arg1 _r9;
    typedef Arg0 _r10;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    enum { arg_size=11 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg10 _r0;
    typedef Arg9 _r1;
    typedef Arg8 _r2;
    typedef Arg7 _r3;
    typedef Arg6 _r4;
    typedef Arg5 _r5;
    typedef Arg4 _r6;
    typedef Arg3 _r7;
    typedef Arg2 _r8;
    typedef Arg1 _r9;
    typedef Arg0 _r10;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    typedef ClassType class_type;
    enum { arg_size=11 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg10 _r0;
    typedef Arg9 _r1;
    typedef Arg8 _r2;
    typedef Arg7 _r3;
    typedef Arg6 _r4;
    typedef Arg5 _r5;
    typedef Arg4 _r6;
    typedef Arg3 _r7;
    typedef Arg2 _r8;
    typedef Arg1 _r9;
    typedef Arg0 _r10;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10);
    typedef ClassType class_type;
    enum { arg_size=11 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg11 _r0;
    typedef Arg10 _r1;
    typedef Arg9 _r2;
    typedef Arg8 _r3;
    typedef Arg7 _r4;
    typedef Arg6 _r5;
    typedef Arg5 _r6;
    typedef Arg4 _r7;
    typedef Arg3 _r8;
    typedef Arg2 _r9;
    typedef Arg1 _r10;
    typedef Arg0 _r11;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    enum { arg_size=12 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg11 _r0;
    typedef Arg10 _r1;
    typedef Arg9 _r2;
    typedef Arg8 _r3;
    typedef Arg7 _r4;
    typedef Arg6 _r5;
    typedef Arg5 _r6;
    typedef Arg4 _r7;
    typedef Arg3 _r8;
    typedef Arg2 _r9;
    typedef Arg1 _r10;
    typedef Arg0 _r11;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    enum { arg_size=12 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg11 _r0;
    typedef Arg10 _r1;
    typedef Arg9 _r2;
    typedef Arg8 _r3;
    typedef Arg7 _r4;
    typedef Arg6 _r5;
    typedef Arg5 _r6;
    typedef Arg4 _r7;
    typedef Arg3 _r8;
    typedef Arg2 _r9;
    typedef Arg1 _r10;
    typedef Arg0 _r11;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    typedef ClassType class_type;
    enum { arg_size=12 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg11 _r0;
    typedef Arg10 _r1;
    typedef Arg9 _r2;
    typedef Arg8 _r3;
    typedef Arg7 _r4;
    typedef Arg6 _r5;
    typedef Arg5 _r6;
    typedef Arg4 _r7;
    typedef Arg3 _r8;
    typedef Arg2 _r9;
    typedef Arg1 _r10;
    typedef Arg0 _r11;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11);
    typedef ClassType class_type;
    enum { arg_size=12 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg12 _r0;
    typedef Arg11 _r1;
    typedef Arg10 _r2;
    typedef Arg9 _r3;
    typedef Arg8 _r4;
    typedef Arg7 _r5;
    typedef Arg6 _r6;
    typedef Arg5 _r7;
    typedef Arg4 _r8;
    typedef Arg3 _r9;
    typedef Arg2 _r10;
    typedef Arg1 _r11;
    typedef Arg0 _r12;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    enum { arg_size=13 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg12 _r0;
    typedef Arg11 _r1;
    typedef Arg10 _r2;
    typedef Arg9 _r3;
    typedef Arg8 _r4;
    typedef Arg7 _r5;
    typedef Arg6 _r6;
    typedef Arg5 _r7;
    typedef Arg4 _r8;
    typedef Arg3 _r9;
    typedef Arg2 _r10;
    typedef Arg1 _r11;
    typedef Arg0 _r12;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    enum { arg_size=13 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg12 _r0;
    typedef Arg11 _r1;
    typedef Arg10 _r2;
    typedef Arg9 _r3;
    typedef Arg8 _r4;
    typedef Arg7 _r5;
    typedef Arg6 _r6;
    typedef Arg5 _r7;
    typedef Arg4 _r8;
    typedef Arg3 _r9;
    typedef Arg2 _r10;
    typedef Arg1 _r11;
    typedef Arg0 _r12;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    typedef ClassType class_type;
    enum { arg_size=13 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg12 _r0;
    typedef Arg11 _r1;
    typedef Arg10 _r2;
    typedef Arg9 _r3;
    typedef Arg8 _r4;
    typedef Arg7 _r5;
    typedef Arg6 _r6;
    typedef Arg5 _r7;
    typedef Arg4 _r8;
    typedef Arg3 _r9;
    typedef Arg2 _r10;
    typedef Arg1 _r11;
    typedef Arg0 _r12;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12);
    typedef ClassType class_type;
    enum { arg_size=13 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg13 _r0;
    typedef Arg12 _r1;
    typedef Arg11 _r2;
    typedef Arg10 _r3;
    typedef Arg9 _r4;
    typedef Arg8 _r5;
    typedef Arg7 _r6;
    typedef Arg6 _r7;
    typedef Arg5 _r8;
    typedef Arg4 _r9;
    typedef Arg3 _r10;
    typedef Arg2 _r11;
    typedef Arg1 _r12;
    typedef Arg0 _r13;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    enum { arg_size=14 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg13 _r0;
    typedef Arg12 _r1;
    typedef Arg11 _r2;
    typedef Arg10 _r3;
    typedef Arg9 _r4;
    typedef Arg8 _r5;
    typedef Arg7 _r6;
    typedef Arg6 _r7;
    typedef Arg5 _r8;
    typedef Arg4 _r9;
    typedef Arg3 _r10;
    typedef Arg2 _r11;
    typedef Arg1 _r12;
    typedef Arg0 _r13;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    enum { arg_size=14 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg13 _r0;
    typedef Arg12 _r1;
    typedef Arg11 _r2;
    typedef Arg10 _r3;
    typedef Arg9 _r4;
    typedef Arg8 _r5;
    typedef Arg7 _r6;
    typedef Arg6 _r7;
    typedef Arg5 _r8;
    typedef Arg4 _r9;
    typedef Arg3 _r10;
    typedef Arg2 _r11;
    typedef Arg1 _r12;
    typedef Arg0 _r13;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    typedef ClassType class_type;
    enum { arg_size=14 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg13 _r0;
    typedef Arg12 _r1;
    typedef Arg11 _r2;
    typedef Arg10 _r3;
    typedef Arg9 _r4;
    typedef Arg8 _r5;
    typedef Arg7 _r6;
    typedef Arg6 _r7;
    typedef Arg5 _r8;
    typedef Arg4 _r9;
    typedef Arg3 _r10;
    typedef Arg2 _r11;
    typedef Arg1 _r12;
    typedef Arg0 _r13;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13);
    typedef ClassType class_type;
    enum { arg_size=14 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg14 _r0;
    typedef Arg13 _r1;
    typedef Arg12 _r2;
    typedef Arg11 _r3;
    typedef Arg10 _r4;
    typedef Arg9 _r5;
    typedef Arg8 _r6;
    typedef Arg7 _r7;
    typedef Arg6 _r8;
    typedef Arg5 _r9;
    typedef Arg4 _r10;
    typedef Arg3 _r11;
    typedef Arg2 _r12;
    typedef Arg1 _r13;
    typedef Arg0 _r14;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    enum { arg_size=15 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg14 _r0;
    typedef Arg13 _r1;
    typedef Arg12 _r2;
    typedef Arg11 _r3;
    typedef Arg10 _r4;
    typedef Arg9 _r5;
    typedef Arg8 _r6;
    typedef Arg7 _r7;
    typedef Arg6 _r8;
    typedef Arg5 _r9;
    typedef Arg4 _r10;
    typedef Arg3 _r11;
    typedef Arg2 _r12;
    typedef Arg1 _r13;
    typedef Arg0 _r14;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    enum { arg_size=15 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg14 _r0;
    typedef Arg13 _r1;
    typedef Arg12 _r2;
    typedef Arg11 _r3;
    typedef Arg10 _r4;
    typedef Arg9 _r5;
    typedef Arg8 _r6;
    typedef Arg7 _r7;
    typedef Arg6 _r8;
    typedef Arg5 _r9;
    typedef Arg4 _r10;
    typedef Arg3 _r11;
    typedef Arg2 _r12;
    typedef Arg1 _r13;
    typedef Arg0 _r14;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    typedef ClassType class_type;
    enum { arg_size=15 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg14 _r0;
    typedef Arg13 _r1;
    typedef Arg12 _r2;
    typedef Arg11 _r3;
    typedef Arg10 _r4;
    typedef Arg9 _r5;
    typedef Arg8 _r6;
    typedef Arg7 _r7;
    typedef Arg6 _r8;
    typedef Arg5 _r9;
    typedef Arg4 _r10;
    typedef Arg3 _r11;
    typedef Arg2 _r12;
    typedef Arg1 _r13;
    typedef Arg0 _r14;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14);
    typedef ClassType class_type;
    enum { arg_size=15 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg15 _r0;
    typedef Arg14 _r1;
    typedef Arg13 _r2;
    typedef Arg12 _r3;
    typedef Arg11 _r4;
    typedef Arg10 _r5;
    typedef Arg9 _r6;
    typedef Arg8 _r7;
    typedef Arg7 _r8;
    typedef Arg6 _r9;
    typedef Arg5 _r10;
    typedef Arg4 _r11;
    typedef Arg3 _r12;
    typedef Arg2 _r13;
    typedef Arg1 _r14;
    typedef Arg0 _r15;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    enum { arg_size=16 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg15 _r0;
    typedef Arg14 _r1;
    typedef Arg13 _r2;
    typedef Arg12 _r3;
    typedef Arg11 _r4;
    typedef Arg10 _r5;
    typedef Arg9 _r6;
    typedef Arg8 _r7;
    typedef Arg7 _r8;
    typedef Arg6 _r9;
    typedef Arg5 _r10;
    typedef Arg4 _r11;
    typedef Arg3 _r12;
    typedef Arg2 _r13;
    typedef Arg1 _r14;
    typedef Arg0 _r15;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    enum { arg_size=16 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg15 _r0;
    typedef Arg14 _r1;
    typedef Arg13 _r2;
    typedef Arg12 _r3;
    typedef Arg11 _r4;
    typedef Arg10 _r5;
    typedef Arg9 _r6;
    typedef Arg8 _r7;
    typedef Arg7 _r8;
    typedef Arg6 _r9;
    typedef Arg5 _r10;
    typedef Arg4 _r11;
    typedef Arg3 _r12;
    typedef Arg2 _r13;
    typedef Arg1 _r14;
    typedef Arg0 _r15;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    typedef ClassType class_type;
    enum { arg_size=16 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg15 _r0;
    typedef Arg14 _r1;
    typedef Arg13 _r2;
    typedef Arg12 _r3;
    typedef Arg11 _r4;
    typedef Arg10 _r5;
    typedef Arg9 _r6;
    typedef Arg8 _r7;
    typedef Arg7 _r8;
    typedef Arg6 _r9;
    typedef Arg5 _r10;
    typedef Arg4 _r11;
    typedef Arg3 _r12;
    typedef Arg2 _r13;
    typedef Arg1 _r14;
    typedef Arg0 _r15;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15);
    typedef ClassType class_type;
    enum { arg_size=16 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg16 _r0;
    typedef Arg15 _r1;
    typedef Arg14 _r2;
    typedef Arg13 _r3;
    typedef Arg12 _r4;
    typedef Arg11 _r5;
    typedef Arg10 _r6;
    typedef Arg9 _r7;
    typedef Arg8 _r8;
    typedef Arg7 _r9;
    typedef Arg6 _r10;
    typedef Arg5 _r11;
    typedef Arg4 _r12;
    typedef Arg3 _r13;
    typedef Arg2 _r14;
    typedef Arg1 _r15;
    typedef Arg0 _r16;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    enum { arg_size=17 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg16 _r0;
    typedef Arg15 _r1;
    typedef Arg14 _r2;
    typedef Arg13 _r3;
    typedef Arg12 _r4;
    typedef Arg11 _r5;
    typedef Arg10 _r6;
    typedef Arg9 _r7;
    typedef Arg8 _r8;
    typedef Arg7 _r9;
    typedef Arg6 _r10;
    typedef Arg5 _r11;
    typedef Arg4 _r12;
    typedef Arg3 _r13;
    typedef Arg2 _r14;
    typedef Arg1 _r15;
    typedef Arg0 _r16;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    enum { arg_size=17 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg16 _r0;
    typedef Arg15 _r1;
    typedef Arg14 _r2;
    typedef Arg13 _r3;
    typedef Arg12 _r4;
    typedef Arg11 _r5;
    typedef Arg10 _r6;
    typedef Arg9 _r7;
    typedef Arg8 _r8;
    typedef Arg7 _r9;
    typedef Arg6 _r10;
    typedef Arg5 _r11;
    typedef Arg4 _r12;
    typedef Arg3 _r13;
    typedef Arg2 _r14;
    typedef Arg1 _r15;
    typedef Arg0 _r16;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    typedef ClassType class_type;
    enum { arg_size=17 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg16 _r0;
    typedef Arg15 _r1;
    typedef Arg14 _r2;
    typedef Arg13 _r3;
    typedef Arg12 _r4;
    typedef Arg11 _r5;
    typedef Arg10 _r6;
    typedef Arg9 _r7;
    typedef Arg8 _r8;
    typedef Arg7 _r9;
    typedef Arg6 _r10;
    typedef Arg5 _r11;
    typedef Arg4 _r12;
    typedef Arg3 _r13;
    typedef Arg2 _r14;
    typedef Arg1 _r15;
    typedef Arg0 _r16;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16);
    typedef ClassType class_type;
    enum { arg_size=17 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg17 _r0;
    typedef Arg16 _r1;
    typedef Arg15 _r2;
    typedef Arg14 _r3;
    typedef Arg13 _r4;
    typedef Arg12 _r5;
    typedef Arg11 _r6;
    typedef Arg10 _r7;
    typedef Arg9 _r8;
    typedef Arg8 _r9;
    typedef Arg7 _r10;
    typedef Arg6 _r11;
    typedef Arg5 _r12;
    typedef Arg4 _r13;
    typedef Arg3 _r14;
    typedef Arg2 _r15;
    typedef Arg1 _r16;
    typedef Arg0 _r17;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    enum { arg_size=18 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg17 _r0;
    typedef Arg16 _r1;
    typedef Arg15 _r2;
    typedef Arg14 _r3;
    typedef Arg13 _r4;
    typedef Arg12 _r5;
    typedef Arg11 _r6;
    typedef Arg10 _r7;
    typedef Arg9 _r8;
    typedef Arg8 _r9;
    typedef Arg7 _r10;
    typedef Arg6 _r11;
    typedef Arg5 _r12;
    typedef Arg4 _r13;
    typedef Arg3 _r14;
    typedef Arg2 _r15;
    typedef Arg1 _r16;
    typedef Arg0 _r17;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    enum { arg_size=18 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg17 _r0;
    typedef Arg16 _r1;
    typedef Arg15 _r2;
    typedef Arg14 _r3;
    typedef Arg13 _r4;
    typedef Arg12 _r5;
    typedef Arg11 _r6;
    typedef Arg10 _r7;
    typedef Arg9 _r8;
    typedef Arg8 _r9;
    typedef Arg7 _r10;
    typedef Arg6 _r11;
    typedef Arg5 _r12;
    typedef Arg4 _r13;
    typedef Arg3 _r14;
    typedef Arg2 _r15;
    typedef Arg1 _r16;
    typedef Arg0 _r17;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    typedef ClassType class_type;
    enum { arg_size=18 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg17 _r0;
    typedef Arg16 _r1;
    typedef Arg15 _r2;
    typedef Arg14 _r3;
    typedef Arg13 _r4;
    typedef Arg12 _r5;
    typedef Arg11 _r6;
    typedef Arg10 _r7;
    typedef Arg9 _r8;
    typedef Arg8 _r9;
    typedef Arg7 _r10;
    typedef Arg6 _r11;
    typedef Arg5 _r12;
    typedef Arg4 _r13;
    typedef Arg3 _r14;
    typedef Arg2 _r15;
    typedef Arg1 _r16;
    typedef Arg0 _r17;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17);
    typedef ClassType class_type;
    enum { arg_size=18 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg18 _r0;
    typedef Arg17 _r1;
    typedef Arg16 _r2;
    typedef Arg15 _r3;
    typedef Arg14 _r4;
    typedef Arg13 _r5;
    typedef Arg12 _r6;
    typedef Arg11 _r7;
    typedef Arg10 _r8;
    typedef Arg9 _r9;
    typedef Arg8 _r10;
    typedef Arg7 _r11;
    typedef Arg6 _r12;
    typedef Arg5 _r13;
    typedef Arg4 _r14;
    typedef Arg3 _r15;
    typedef Arg2 _r16;
    typedef Arg1 _r17;
    typedef Arg0 _r18;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    enum { arg_size=19 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg18 _r0;
    typedef Arg17 _r1;
    typedef Arg16 _r2;
    typedef Arg15 _r3;
    typedef Arg14 _r4;
    typedef Arg13 _r5;
    typedef Arg12 _r6;
    typedef Arg11 _r7;
    typedef Arg10 _r8;
    typedef Arg9 _r9;
    typedef Arg8 _r10;
    typedef Arg7 _r11;
    typedef Arg6 _r12;
    typedef Arg5 _r13;
    typedef Arg4 _r14;
    typedef Arg3 _r15;
    typedef Arg2 _r16;
    typedef Arg1 _r17;
    typedef Arg0 _r18;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    enum { arg_size=19 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg18 _r0;
    typedef Arg17 _r1;
    typedef Arg16 _r2;
    typedef Arg15 _r3;
    typedef Arg14 _r4;
    typedef Arg13 _r5;
    typedef Arg12 _r6;
    typedef Arg11 _r7;
    typedef Arg10 _r8;
    typedef Arg9 _r9;
    typedef Arg8 _r10;
    typedef Arg7 _r11;
    typedef Arg6 _r12;
    typedef Arg5 _r13;
    typedef Arg4 _r14;
    typedef Arg3 _r15;
    typedef Arg2 _r16;
    typedef Arg1 _r17;
    typedef Arg0 _r18;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    typedef std::function< ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18) > stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    typedef ClassType class_type;
    enum { arg_size=19 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg18 _r0;
    typedef Arg17 _r1;
    typedef Arg16 _r2;
    typedef Arg15 _r3;
    typedef Arg14 _r4;
    typedef Arg13 _r5;
    typedef Arg12 _r6;
    typedef Arg11 _r7;
    typedef Arg10 _r8;
    typedef Arg9 _r9;
    typedef Arg8 _r10;
    typedef Arg7 _r11;
    typedef Arg6 _r12;
    typedef Arg5 _r13;
    typedef Arg4 _r14;
    typedef Arg3 _r15;
    typedef Arg2 _r16;
    typedef Arg1 _r17;
    typedef Arg0 _r18;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18) const;
    typedef std::function< ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18)  > stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18);
    typedef ClassType class_type;
    enum { arg_size=19 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19
>
class FunctionType< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg19 _r0;
    typedef Arg18 _r1;
    typedef Arg17 _r2;
    typedef Arg16 _r3;
    typedef Arg15 _r4;
    typedef Arg14 _r5;
    typedef Arg13 _r6;
    typedef Arg12 _r7;
    typedef Arg11 _r8;
    typedef Arg10 _r9;
    typedef Arg9 _r10;
    typedef Arg8 _r11;
    typedef Arg7 _r12;
    typedef Arg6 _r13;
    typedef Arg5 _r14;
    typedef Arg4 _r15;
    typedef Arg3 _r16;
    typedef Arg2 _r17;
    typedef Arg1 _r18;
    typedef Arg0 _r19;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    enum { arg_size=20 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19
>
class FunctionType< std::function< ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19) > > : public FunctionType< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19) >
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19
>
class FunctionType< ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg19 _r0;
    typedef Arg18 _r1;
    typedef Arg17 _r2;
    typedef Arg16 _r3;
    typedef Arg15 _r4;
    typedef Arg14 _r5;
    typedef Arg13 _r6;
    typedef Arg12 _r7;
    typedef Arg11 _r8;
    typedef Arg10 _r9;
    typedef Arg9 _r10;
    typedef Arg8 _r11;
    typedef Arg7 _r12;
    typedef Arg6 _r13;
    typedef Arg5 _r14;
    typedef Arg4 _r15;
    typedef Arg3 _r16;
    typedef Arg2 _r17;
    typedef Arg1 _r18;
    typedef Arg0 _r19;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    typedef std::function< ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19) > stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    enum { arg_size=20 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19) > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg19 _r0;
    typedef Arg18 _r1;
    typedef Arg17 _r2;
    typedef Arg16 _r3;
    typedef Arg15 _r4;
    typedef Arg14 _r5;
    typedef Arg13 _r6;
    typedef Arg12 _r7;
    typedef Arg11 _r8;
    typedef Arg10 _r9;
    typedef Arg9 _r10;
    typedef Arg8 _r11;
    typedef Arg7 _r12;
    typedef Arg6 _r13;
    typedef Arg5 _r14;
    typedef Arg4 _r15;
    typedef Arg3 _r16;
    typedef Arg2 _r17;
    typedef Arg1 _r18;
    typedef Arg0 _r19;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    typedef ClassType class_type;
    enum { arg_size=20 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19
>
class FunctionType< ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19) const > {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg19 _r0;
    typedef Arg18 _r1;
    typedef Arg17 _r2;
    typedef Arg16 _r3;
    typedef Arg15 _r4;
    typedef Arg14 _r5;
    typedef Arg13 _r6;
    typedef Arg12 _r7;
    typedef Arg11 _r8;
    typedef Arg10 _r9;
    typedef Arg9 _r10;
    typedef Arg8 _r11;
    typedef Arg7 _r12;
    typedef Arg6 _r13;
    typedef Arg5 _r14;
    typedef Arg4 _r15;
    typedef Arg3 _r16;
    typedef Arg2 _r17;
    typedef Arg1 _r18;
    typedef Arg0 _r19;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19);
    typedef ClassType class_type;
    enum { arg_size=20 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg20 _r0;
    typedef Arg19 _r1;
    typedef Arg18 _r2;
    typedef Arg17 _r3;
    typedef Arg16 _r4;
    typedef Arg15 _r5;
    typedef Arg14 _r6;
    typedef Arg13 _r7;
    typedef Arg12 _r8;
    typedef Arg11 _r9;
    typedef Arg10 _r10;
    typedef Arg9 _r11;
    typedef Arg8 _r12;
    typedef Arg7 _r13;
    typedef Arg6 _r14;
    typedef Arg5 _r15;
    typedef Arg4 _r16;
    typedef Arg3 _r17;
    typedef Arg2 _r18;
    typedef Arg1 _r19;
    typedef Arg0 _r20;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    enum { arg_size=21 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg20 _r0;
    typedef Arg19 _r1;
    typedef Arg18 _r2;
    typedef Arg17 _r3;
    typedef Arg16 _r4;
    typedef Arg15 _r5;
    typedef Arg14 _r6;
    typedef Arg13 _r7;
    typedef Arg12 _r8;
    typedef Arg11 _r9;
    typedef Arg10 _r10;
    typedef Arg9 _r11;
    typedef Arg8 _r12;
    typedef Arg7 _r13;
    typedef Arg6 _r14;
    typedef Arg5 _r15;
    typedef Arg4 _r16;
    typedef Arg3 _r17;
    typedef Arg2 _r18;
    typedef Arg1 _r19;
    typedef Arg0 _r20;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    enum { arg_size=21 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg20 _r0;
    typedef Arg19 _r1;
    typedef Arg18 _r2;
    typedef Arg17 _r3;
    typedef Arg16 _r4;
    typedef Arg15 _r5;
    typedef Arg14 _r6;
    typedef Arg13 _r7;
    typedef Arg12 _r8;
    typedef Arg11 _r9;
    typedef Arg10 _r10;
    typedef Arg9 _r11;
    typedef Arg8 _r12;
    typedef Arg7 _r13;
    typedef Arg6 _r14;
    typedef Arg5 _r15;
    typedef Arg4 _r16;
    typedef Arg3 _r17;
    typedef Arg2 _r18;
    typedef Arg1 _r19;
    typedef Arg0 _r20;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    typedef ClassType class_type;
    enum { arg_size=21 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg20 _r0;
    typedef Arg19 _r1;
    typedef Arg18 _r2;
    typedef Arg17 _r3;
    typedef Arg16 _r4;
    typedef Arg15 _r5;
    typedef Arg14 _r6;
    typedef Arg13 _r7;
    typedef Arg12 _r8;
    typedef Arg11 _r9;
    typedef Arg10 _r10;
    typedef Arg9 _r11;
    typedef Arg8 _r12;
    typedef Arg7 _r13;
    typedef Arg6 _r14;
    typedef Arg5 _r15;
    typedef Arg4 _r16;
    typedef Arg3 _r17;
    typedef Arg2 _r18;
    typedef Arg1 _r19;
    typedef Arg0 _r20;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20);
    typedef ClassType class_type;
    enum { arg_size=21 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg21 _r0;
    typedef Arg20 _r1;
    typedef Arg19 _r2;
    typedef Arg18 _r3;
    typedef Arg17 _r4;
    typedef Arg16 _r5;
    typedef Arg15 _r6;
    typedef Arg14 _r7;
    typedef Arg13 _r8;
    typedef Arg12 _r9;
    typedef Arg11 _r10;
    typedef Arg10 _r11;
    typedef Arg9 _r12;
    typedef Arg8 _r13;
    typedef Arg7 _r14;
    typedef Arg6 _r15;
    typedef Arg5 _r16;
    typedef Arg4 _r17;
    typedef Arg3 _r18;
    typedef Arg2 _r19;
    typedef Arg1 _r20;
    typedef Arg0 _r21;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    enum { arg_size=22 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg21 _r0;
    typedef Arg20 _r1;
    typedef Arg19 _r2;
    typedef Arg18 _r3;
    typedef Arg17 _r4;
    typedef Arg16 _r5;
    typedef Arg15 _r6;
    typedef Arg14 _r7;
    typedef Arg13 _r8;
    typedef Arg12 _r9;
    typedef Arg11 _r10;
    typedef Arg10 _r11;
    typedef Arg9 _r12;
    typedef Arg8 _r13;
    typedef Arg7 _r14;
    typedef Arg6 _r15;
    typedef Arg5 _r16;
    typedef Arg4 _r17;
    typedef Arg3 _r18;
    typedef Arg2 _r19;
    typedef Arg1 _r20;
    typedef Arg0 _r21;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    enum { arg_size=22 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg21 _r0;
    typedef Arg20 _r1;
    typedef Arg19 _r2;
    typedef Arg18 _r3;
    typedef Arg17 _r4;
    typedef Arg16 _r5;
    typedef Arg15 _r6;
    typedef Arg14 _r7;
    typedef Arg13 _r8;
    typedef Arg12 _r9;
    typedef Arg11 _r10;
    typedef Arg10 _r11;
    typedef Arg9 _r12;
    typedef Arg8 _r13;
    typedef Arg7 _r14;
    typedef Arg6 _r15;
    typedef Arg5 _r16;
    typedef Arg4 _r17;
    typedef Arg3 _r18;
    typedef Arg2 _r19;
    typedef Arg1 _r20;
    typedef Arg0 _r21;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    typedef ClassType class_type;
    enum { arg_size=22 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg21 _r0;
    typedef Arg20 _r1;
    typedef Arg19 _r2;
    typedef Arg18 _r3;
    typedef Arg17 _r4;
    typedef Arg16 _r5;
    typedef Arg15 _r6;
    typedef Arg14 _r7;
    typedef Arg13 _r8;
    typedef Arg12 _r9;
    typedef Arg11 _r10;
    typedef Arg10 _r11;
    typedef Arg9 _r12;
    typedef Arg8 _r13;
    typedef Arg7 _r14;
    typedef Arg6 _r15;
    typedef Arg5 _r16;
    typedef Arg4 _r17;
    typedef Arg3 _r18;
    typedef Arg2 _r19;
    typedef Arg1 _r20;
    typedef Arg0 _r21;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21);
    typedef ClassType class_type;
    enum { arg_size=22 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg22 _r0;
    typedef Arg21 _r1;
    typedef Arg20 _r2;
    typedef Arg19 _r3;
    typedef Arg18 _r4;
    typedef Arg17 _r5;
    typedef Arg16 _r6;
    typedef Arg15 _r7;
    typedef Arg14 _r8;
    typedef Arg13 _r9;
    typedef Arg12 _r10;
    typedef Arg11 _r11;
    typedef Arg10 _r12;
    typedef Arg9 _r13;
    typedef Arg8 _r14;
    typedef Arg7 _r15;
    typedef Arg6 _r16;
    typedef Arg5 _r17;
    typedef Arg4 _r18;
    typedef Arg3 _r19;
    typedef Arg2 _r20;
    typedef Arg1 _r21;
    typedef Arg0 _r22;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    enum { arg_size=23 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg22 _r0;
    typedef Arg21 _r1;
    typedef Arg20 _r2;
    typedef Arg19 _r3;
    typedef Arg18 _r4;
    typedef Arg17 _r5;
    typedef Arg16 _r6;
    typedef Arg15 _r7;
    typedef Arg14 _r8;
    typedef Arg13 _r9;
    typedef Arg12 _r10;
    typedef Arg11 _r11;
    typedef Arg10 _r12;
    typedef Arg9 _r13;
    typedef Arg8 _r14;
    typedef Arg7 _r15;
    typedef Arg6 _r16;
    typedef Arg5 _r17;
    typedef Arg4 _r18;
    typedef Arg3 _r19;
    typedef Arg2 _r20;
    typedef Arg1 _r21;
    typedef Arg0 _r22;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    enum { arg_size=23 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg22 _r0;
    typedef Arg21 _r1;
    typedef Arg20 _r2;
    typedef Arg19 _r3;
    typedef Arg18 _r4;
    typedef Arg17 _r5;
    typedef Arg16 _r6;
    typedef Arg15 _r7;
    typedef Arg14 _r8;
    typedef Arg13 _r9;
    typedef Arg12 _r10;
    typedef Arg11 _r11;
    typedef Arg10 _r12;
    typedef Arg9 _r13;
    typedef Arg8 _r14;
    typedef Arg7 _r15;
    typedef Arg6 _r16;
    typedef Arg5 _r17;
    typedef Arg4 _r18;
    typedef Arg3 _r19;
    typedef Arg2 _r20;
    typedef Arg1 _r21;
    typedef Arg0 _r22;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    typedef ClassType class_type;
    enum { arg_size=23 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg22 _r0;
    typedef Arg21 _r1;
    typedef Arg20 _r2;
    typedef Arg19 _r3;
    typedef Arg18 _r4;
    typedef Arg17 _r5;
    typedef Arg16 _r6;
    typedef Arg15 _r7;
    typedef Arg14 _r8;
    typedef Arg13 _r9;
    typedef Arg12 _r10;
    typedef Arg11 _r11;
    typedef Arg10 _r12;
    typedef Arg9 _r13;
    typedef Arg8 _r14;
    typedef Arg7 _r15;
    typedef Arg6 _r16;
    typedef Arg5 _r17;
    typedef Arg4 _r18;
    typedef Arg3 _r19;
    typedef Arg2 _r20;
    typedef Arg1 _r21;
    typedef Arg0 _r22;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22);
    typedef ClassType class_type;
    enum { arg_size=23 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg23 _r0;
    typedef Arg22 _r1;
    typedef Arg21 _r2;
    typedef Arg20 _r3;
    typedef Arg19 _r4;
    typedef Arg18 _r5;
    typedef Arg17 _r6;
    typedef Arg16 _r7;
    typedef Arg15 _r8;
    typedef Arg14 _r9;
    typedef Arg13 _r10;
    typedef Arg12 _r11;
    typedef Arg11 _r12;
    typedef Arg10 _r13;
    typedef Arg9 _r14;
    typedef Arg8 _r15;
    typedef Arg7 _r16;
    typedef Arg6 _r17;
    typedef Arg5 _r18;
    typedef Arg4 _r19;
    typedef Arg3 _r20;
    typedef Arg2 _r21;
    typedef Arg1 _r22;
    typedef Arg0 _r23;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    enum { arg_size=24 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg23 _r0;
    typedef Arg22 _r1;
    typedef Arg21 _r2;
    typedef Arg20 _r3;
    typedef Arg19 _r4;
    typedef Arg18 _r5;
    typedef Arg17 _r6;
    typedef Arg16 _r7;
    typedef Arg15 _r8;
    typedef Arg14 _r9;
    typedef Arg13 _r10;
    typedef Arg12 _r11;
    typedef Arg11 _r12;
    typedef Arg10 _r13;
    typedef Arg9 _r14;
    typedef Arg8 _r15;
    typedef Arg7 _r16;
    typedef Arg6 _r17;
    typedef Arg5 _r18;
    typedef Arg4 _r19;
    typedef Arg3 _r20;
    typedef Arg2 _r21;
    typedef Arg1 _r22;
    typedef Arg0 _r23;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    enum { arg_size=24 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg23 _r0;
    typedef Arg22 _r1;
    typedef Arg21 _r2;
    typedef Arg20 _r3;
    typedef Arg19 _r4;
    typedef Arg18 _r5;
    typedef Arg17 _r6;
    typedef Arg16 _r7;
    typedef Arg15 _r8;
    typedef Arg14 _r9;
    typedef Arg13 _r10;
    typedef Arg12 _r11;
    typedef Arg11 _r12;
    typedef Arg10 _r13;
    typedef Arg9 _r14;
    typedef Arg8 _r15;
    typedef Arg7 _r16;
    typedef Arg6 _r17;
    typedef Arg5 _r18;
    typedef Arg4 _r19;
    typedef Arg3 _r20;
    typedef Arg2 _r21;
    typedef Arg1 _r22;
    typedef Arg0 _r23;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    typedef ClassType class_type;
    enum { arg_size=24 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg23 _r0;
    typedef Arg22 _r1;
    typedef Arg21 _r2;
    typedef Arg20 _r3;
    typedef Arg19 _r4;
    typedef Arg18 _r5;
    typedef Arg17 _r6;
    typedef Arg16 _r7;
    typedef Arg15 _r8;
    typedef Arg14 _r9;
    typedef Arg13 _r10;
    typedef Arg12 _r11;
    typedef Arg11 _r12;
    typedef Arg10 _r13;
    typedef Arg9 _r14;
    typedef Arg8 _r15;
    typedef Arg7 _r16;
    typedef Arg6 _r17;
    typedef Arg5 _r18;
    typedef Arg4 _r19;
    typedef Arg3 _r20;
    typedef Arg2 _r21;
    typedef Arg1 _r22;
    typedef Arg0 _r23;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23);
    typedef ClassType class_type;
    enum { arg_size=24 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg24 _r0;
    typedef Arg23 _r1;
    typedef Arg22 _r2;
    typedef Arg21 _r3;
    typedef Arg20 _r4;
    typedef Arg19 _r5;
    typedef Arg18 _r6;
    typedef Arg17 _r7;
    typedef Arg16 _r8;
    typedef Arg15 _r9;
    typedef Arg14 _r10;
    typedef Arg13 _r11;
    typedef Arg12 _r12;
    typedef Arg11 _r13;
    typedef Arg10 _r14;
    typedef Arg9 _r15;
    typedef Arg8 _r16;
    typedef Arg7 _r17;
    typedef Arg6 _r18;
    typedef Arg5 _r19;
    typedef Arg4 _r20;
    typedef Arg3 _r21;
    typedef Arg2 _r22;
    typedef Arg1 _r23;
    typedef Arg0 _r24;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    enum { arg_size=25 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg24 _r0;
    typedef Arg23 _r1;
    typedef Arg22 _r2;
    typedef Arg21 _r3;
    typedef Arg20 _r4;
    typedef Arg19 _r5;
    typedef Arg18 _r6;
    typedef Arg17 _r7;
    typedef Arg16 _r8;
    typedef Arg15 _r9;
    typedef Arg14 _r10;
    typedef Arg13 _r11;
    typedef Arg12 _r12;
    typedef Arg11 _r13;
    typedef Arg10 _r14;
    typedef Arg9 _r15;
    typedef Arg8 _r16;
    typedef Arg7 _r17;
    typedef Arg6 _r18;
    typedef Arg5 _r19;
    typedef Arg4 _r20;
    typedef Arg3 _r21;
    typedef Arg2 _r22;
    typedef Arg1 _r23;
    typedef Arg0 _r24;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    enum { arg_size=25 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg24 _r0;
    typedef Arg23 _r1;
    typedef Arg22 _r2;
    typedef Arg21 _r3;
    typedef Arg20 _r4;
    typedef Arg19 _r5;
    typedef Arg18 _r6;
    typedef Arg17 _r7;
    typedef Arg16 _r8;
    typedef Arg15 _r9;
    typedef Arg14 _r10;
    typedef Arg13 _r11;
    typedef Arg12 _r12;
    typedef Arg11 _r13;
    typedef Arg10 _r14;
    typedef Arg9 _r15;
    typedef Arg8 _r16;
    typedef Arg7 _r17;
    typedef Arg6 _r18;
    typedef Arg5 _r19;
    typedef Arg4 _r20;
    typedef Arg3 _r21;
    typedef Arg2 _r22;
    typedef Arg1 _r23;
    typedef Arg0 _r24;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    typedef ClassType class_type;
    enum { arg_size=25 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg24 _r0;
    typedef Arg23 _r1;
    typedef Arg22 _r2;
    typedef Arg21 _r3;
    typedef Arg20 _r4;
    typedef Arg19 _r5;
    typedef Arg18 _r6;
    typedef Arg17 _r7;
    typedef Arg16 _r8;
    typedef Arg15 _r9;
    typedef Arg14 _r10;
    typedef Arg13 _r11;
    typedef Arg12 _r12;
    typedef Arg11 _r13;
    typedef Arg10 _r14;
    typedef Arg9 _r15;
    typedef Arg8 _r16;
    typedef Arg7 _r17;
    typedef Arg6 _r18;
    typedef Arg5 _r19;
    typedef Arg4 _r20;
    typedef Arg3 _r21;
    typedef Arg2 _r22;
    typedef Arg1 _r23;
    typedef Arg0 _r24;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24);
    typedef ClassType class_type;
    enum { arg_size=25 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg25 _r0;
    typedef Arg24 _r1;
    typedef Arg23 _r2;
    typedef Arg22 _r3;
    typedef Arg21 _r4;
    typedef Arg20 _r5;
    typedef Arg19 _r6;
    typedef Arg18 _r7;
    typedef Arg17 _r8;
    typedef Arg16 _r9;
    typedef Arg15 _r10;
    typedef Arg14 _r11;
    typedef Arg13 _r12;
    typedef Arg12 _r13;
    typedef Arg11 _r14;
    typedef Arg10 _r15;
    typedef Arg9 _r16;
    typedef Arg8 _r17;
    typedef Arg7 _r18;
    typedef Arg6 _r19;
    typedef Arg5 _r20;
    typedef Arg4 _r21;
    typedef Arg3 _r22;
    typedef Arg2 _r23;
    typedef Arg1 _r24;
    typedef Arg0 _r25;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    enum { arg_size=26 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg25 _r0;
    typedef Arg24 _r1;
    typedef Arg23 _r2;
    typedef Arg22 _r3;
    typedef Arg21 _r4;
    typedef Arg20 _r5;
    typedef Arg19 _r6;
    typedef Arg18 _r7;
    typedef Arg17 _r8;
    typedef Arg16 _r9;
    typedef Arg15 _r10;
    typedef Arg14 _r11;
    typedef Arg13 _r12;
    typedef Arg12 _r13;
    typedef Arg11 _r14;
    typedef Arg10 _r15;
    typedef Arg9 _r16;
    typedef Arg8 _r17;
    typedef Arg7 _r18;
    typedef Arg6 _r19;
    typedef Arg5 _r20;
    typedef Arg4 _r21;
    typedef Arg3 _r22;
    typedef Arg2 _r23;
    typedef Arg1 _r24;
    typedef Arg0 _r25;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    enum { arg_size=26 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg25 _r0;
    typedef Arg24 _r1;
    typedef Arg23 _r2;
    typedef Arg22 _r3;
    typedef Arg21 _r4;
    typedef Arg20 _r5;
    typedef Arg19 _r6;
    typedef Arg18 _r7;
    typedef Arg17 _r8;
    typedef Arg16 _r9;
    typedef Arg15 _r10;
    typedef Arg14 _r11;
    typedef Arg13 _r12;
    typedef Arg12 _r13;
    typedef Arg11 _r14;
    typedef Arg10 _r15;
    typedef Arg9 _r16;
    typedef Arg8 _r17;
    typedef Arg7 _r18;
    typedef Arg6 _r19;
    typedef Arg5 _r20;
    typedef Arg4 _r21;
    typedef Arg3 _r22;
    typedef Arg2 _r23;
    typedef Arg1 _r24;
    typedef Arg0 _r25;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    typedef ClassType class_type;
    enum { arg_size=26 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg25 _r0;
    typedef Arg24 _r1;
    typedef Arg23 _r2;
    typedef Arg22 _r3;
    typedef Arg21 _r4;
    typedef Arg20 _r5;
    typedef Arg19 _r6;
    typedef Arg18 _r7;
    typedef Arg17 _r8;
    typedef Arg16 _r9;
    typedef Arg15 _r10;
    typedef Arg14 _r11;
    typedef Arg13 _r12;
    typedef Arg12 _r13;
    typedef Arg11 _r14;
    typedef Arg10 _r15;
    typedef Arg9 _r16;
    typedef Arg8 _r17;
    typedef Arg7 _r18;
    typedef Arg6 _r19;
    typedef Arg5 _r20;
    typedef Arg4 _r21;
    typedef Arg3 _r22;
    typedef Arg2 _r23;
    typedef Arg1 _r24;
    typedef Arg0 _r25;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25);
    typedef ClassType class_type;
    enum { arg_size=26 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg26 _r0;
    typedef Arg25 _r1;
    typedef Arg24 _r2;
    typedef Arg23 _r3;
    typedef Arg22 _r4;
    typedef Arg21 _r5;
    typedef Arg20 _r6;
    typedef Arg19 _r7;
    typedef Arg18 _r8;
    typedef Arg17 _r9;
    typedef Arg16 _r10;
    typedef Arg15 _r11;
    typedef Arg14 _r12;
    typedef Arg13 _r13;
    typedef Arg12 _r14;
    typedef Arg11 _r15;
    typedef Arg10 _r16;
    typedef Arg9 _r17;
    typedef Arg8 _r18;
    typedef Arg7 _r19;
    typedef Arg6 _r20;
    typedef Arg5 _r21;
    typedef Arg4 _r22;
    typedef Arg3 _r23;
    typedef Arg2 _r24;
    typedef Arg1 _r25;
    typedef Arg0 _r26;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    enum { arg_size=27 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg26 _r0;
    typedef Arg25 _r1;
    typedef Arg24 _r2;
    typedef Arg23 _r3;
    typedef Arg22 _r4;
    typedef Arg21 _r5;
    typedef Arg20 _r6;
    typedef Arg19 _r7;
    typedef Arg18 _r8;
    typedef Arg17 _r9;
    typedef Arg16 _r10;
    typedef Arg15 _r11;
    typedef Arg14 _r12;
    typedef Arg13 _r13;
    typedef Arg12 _r14;
    typedef Arg11 _r15;
    typedef Arg10 _r16;
    typedef Arg9 _r17;
    typedef Arg8 _r18;
    typedef Arg7 _r19;
    typedef Arg6 _r20;
    typedef Arg5 _r21;
    typedef Arg4 _r22;
    typedef Arg3 _r23;
    typedef Arg2 _r24;
    typedef Arg1 _r25;
    typedef Arg0 _r26;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    enum { arg_size=27 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg26 _r0;
    typedef Arg25 _r1;
    typedef Arg24 _r2;
    typedef Arg23 _r3;
    typedef Arg22 _r4;
    typedef Arg21 _r5;
    typedef Arg20 _r6;
    typedef Arg19 _r7;
    typedef Arg18 _r8;
    typedef Arg17 _r9;
    typedef Arg16 _r10;
    typedef Arg15 _r11;
    typedef Arg14 _r12;
    typedef Arg13 _r13;
    typedef Arg12 _r14;
    typedef Arg11 _r15;
    typedef Arg10 _r16;
    typedef Arg9 _r17;
    typedef Arg8 _r18;
    typedef Arg7 _r19;
    typedef Arg6 _r20;
    typedef Arg5 _r21;
    typedef Arg4 _r22;
    typedef Arg3 _r23;
    typedef Arg2 _r24;
    typedef Arg1 _r25;
    typedef Arg0 _r26;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    typedef ClassType class_type;
    enum { arg_size=27 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg26 _r0;
    typedef Arg25 _r1;
    typedef Arg24 _r2;
    typedef Arg23 _r3;
    typedef Arg22 _r4;
    typedef Arg21 _r5;
    typedef Arg20 _r6;
    typedef Arg19 _r7;
    typedef Arg18 _r8;
    typedef Arg17 _r9;
    typedef Arg16 _r10;
    typedef Arg15 _r11;
    typedef Arg14 _r12;
    typedef Arg13 _r13;
    typedef Arg12 _r14;
    typedef Arg11 _r15;
    typedef Arg10 _r16;
    typedef Arg9 _r17;
    typedef Arg8 _r18;
    typedef Arg7 _r19;
    typedef Arg6 _r20;
    typedef Arg5 _r21;
    typedef Arg4 _r22;
    typedef Arg3 _r23;
    typedef Arg2 _r24;
    typedef Arg1 _r25;
    typedef Arg0 _r26;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26);
    typedef ClassType class_type;
    enum { arg_size=27 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg27 _r0;
    typedef Arg26 _r1;
    typedef Arg25 _r2;
    typedef Arg24 _r3;
    typedef Arg23 _r4;
    typedef Arg22 _r5;
    typedef Arg21 _r6;
    typedef Arg20 _r7;
    typedef Arg19 _r8;
    typedef Arg18 _r9;
    typedef Arg17 _r10;
    typedef Arg16 _r11;
    typedef Arg15 _r12;
    typedef Arg14 _r13;
    typedef Arg13 _r14;
    typedef Arg12 _r15;
    typedef Arg11 _r16;
    typedef Arg10 _r17;
    typedef Arg9 _r18;
    typedef Arg8 _r19;
    typedef Arg7 _r20;
    typedef Arg6 _r21;
    typedef Arg5 _r22;
    typedef Arg4 _r23;
    typedef Arg3 _r24;
    typedef Arg2 _r25;
    typedef Arg1 _r26;
    typedef Arg0 _r27;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    enum { arg_size=28 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg27 _r0;
    typedef Arg26 _r1;
    typedef Arg25 _r2;
    typedef Arg24 _r3;
    typedef Arg23 _r4;
    typedef Arg22 _r5;
    typedef Arg21 _r6;
    typedef Arg20 _r7;
    typedef Arg19 _r8;
    typedef Arg18 _r9;
    typedef Arg17 _r10;
    typedef Arg16 _r11;
    typedef Arg15 _r12;
    typedef Arg14 _r13;
    typedef Arg13 _r14;
    typedef Arg12 _r15;
    typedef Arg11 _r16;
    typedef Arg10 _r17;
    typedef Arg9 _r18;
    typedef Arg8 _r19;
    typedef Arg7 _r20;
    typedef Arg6 _r21;
    typedef Arg5 _r22;
    typedef Arg4 _r23;
    typedef Arg3 _r24;
    typedef Arg2 _r25;
    typedef Arg1 _r26;
    typedef Arg0 _r27;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    enum { arg_size=28 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg27 _r0;
    typedef Arg26 _r1;
    typedef Arg25 _r2;
    typedef Arg24 _r3;
    typedef Arg23 _r4;
    typedef Arg22 _r5;
    typedef Arg21 _r6;
    typedef Arg20 _r7;
    typedef Arg19 _r8;
    typedef Arg18 _r9;
    typedef Arg17 _r10;
    typedef Arg16 _r11;
    typedef Arg15 _r12;
    typedef Arg14 _r13;
    typedef Arg13 _r14;
    typedef Arg12 _r15;
    typedef Arg11 _r16;
    typedef Arg10 _r17;
    typedef Arg9 _r18;
    typedef Arg8 _r19;
    typedef Arg7 _r20;
    typedef Arg6 _r21;
    typedef Arg5 _r22;
    typedef Arg4 _r23;
    typedef Arg3 _r24;
    typedef Arg2 _r25;
    typedef Arg1 _r26;
    typedef Arg0 _r27;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    typedef ClassType class_type;
    enum { arg_size=28 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg27 _r0;
    typedef Arg26 _r1;
    typedef Arg25 _r2;
    typedef Arg24 _r3;
    typedef Arg23 _r4;
    typedef Arg22 _r5;
    typedef Arg21 _r6;
    typedef Arg20 _r7;
    typedef Arg19 _r8;
    typedef Arg18 _r9;
    typedef Arg17 _r10;
    typedef Arg16 _r11;
    typedef Arg15 _r12;
    typedef Arg14 _r13;
    typedef Arg13 _r14;
    typedef Arg12 _r15;
    typedef Arg11 _r16;
    typedef Arg10 _r17;
    typedef Arg9 _r18;
    typedef Arg8 _r19;
    typedef Arg7 _r20;
    typedef Arg6 _r21;
    typedef Arg5 _r22;
    typedef Arg4 _r23;
    typedef Arg3 _r24;
    typedef Arg2 _r25;
    typedef Arg1 _r26;
    typedef Arg0 _r27;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27);
    typedef ClassType class_type;
    enum { arg_size=28 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg28 _r0;
    typedef Arg27 _r1;
    typedef Arg26 _r2;
    typedef Arg25 _r3;
    typedef Arg24 _r4;
    typedef Arg23 _r5;
    typedef Arg22 _r6;
    typedef Arg21 _r7;
    typedef Arg20 _r8;
    typedef Arg19 _r9;
    typedef Arg18 _r10;
    typedef Arg17 _r11;
    typedef Arg16 _r12;
    typedef Arg15 _r13;
    typedef Arg14 _r14;
    typedef Arg13 _r15;
    typedef Arg12 _r16;
    typedef Arg11 _r17;
    typedef Arg10 _r18;
    typedef Arg9 _r19;
    typedef Arg8 _r20;
    typedef Arg7 _r21;
    typedef Arg6 _r22;
    typedef Arg5 _r23;
    typedef Arg4 _r24;
    typedef Arg3 _r25;
    typedef Arg2 _r26;
    typedef Arg1 _r27;
    typedef Arg0 _r28;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    enum { arg_size=29 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg28 _r0;
    typedef Arg27 _r1;
    typedef Arg26 _r2;
    typedef Arg25 _r3;
    typedef Arg24 _r4;
    typedef Arg23 _r5;
    typedef Arg22 _r6;
    typedef Arg21 _r7;
    typedef Arg20 _r8;
    typedef Arg19 _r9;
    typedef Arg18 _r10;
    typedef Arg17 _r11;
    typedef Arg16 _r12;
    typedef Arg15 _r13;
    typedef Arg14 _r14;
    typedef Arg13 _r15;
    typedef Arg12 _r16;
    typedef Arg11 _r17;
    typedef Arg10 _r18;
    typedef Arg9 _r19;
    typedef Arg8 _r20;
    typedef Arg7 _r21;
    typedef Arg6 _r22;
    typedef Arg5 _r23;
    typedef Arg4 _r24;
    typedef Arg3 _r25;
    typedef Arg2 _r26;
    typedef Arg1 _r27;
    typedef Arg0 _r28;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    enum { arg_size=29 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg28 _r0;
    typedef Arg27 _r1;
    typedef Arg26 _r2;
    typedef Arg25 _r3;
    typedef Arg24 _r4;
    typedef Arg23 _r5;
    typedef Arg22 _r6;
    typedef Arg21 _r7;
    typedef Arg20 _r8;
    typedef Arg19 _r9;
    typedef Arg18 _r10;
    typedef Arg17 _r11;
    typedef Arg16 _r12;
    typedef Arg15 _r13;
    typedef Arg14 _r14;
    typedef Arg13 _r15;
    typedef Arg12 _r16;
    typedef Arg11 _r17;
    typedef Arg10 _r18;
    typedef Arg9 _r19;
    typedef Arg8 _r20;
    typedef Arg7 _r21;
    typedef Arg6 _r22;
    typedef Arg5 _r23;
    typedef Arg4 _r24;
    typedef Arg3 _r25;
    typedef Arg2 _r26;
    typedef Arg1 _r27;
    typedef Arg0 _r28;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    typedef ClassType class_type;
    enum { arg_size=29 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg28 _r0;
    typedef Arg27 _r1;
    typedef Arg26 _r2;
    typedef Arg25 _r3;
    typedef Arg24 _r4;
    typedef Arg23 _r5;
    typedef Arg22 _r6;
    typedef Arg21 _r7;
    typedef Arg20 _r8;
    typedef Arg19 _r9;
    typedef Arg18 _r10;
    typedef Arg17 _r11;
    typedef Arg16 _r12;
    typedef Arg15 _r13;
    typedef Arg14 _r14;
    typedef Arg13 _r15;
    typedef Arg12 _r16;
    typedef Arg11 _r17;
    typedef Arg10 _r18;
    typedef Arg9 _r19;
    typedef Arg8 _r20;
    typedef Arg7 _r21;
    typedef Arg6 _r22;
    typedef Arg5 _r23;
    typedef Arg4 _r24;
    typedef Arg3 _r25;
    typedef Arg2 _r26;
    typedef Arg1 _r27;
    typedef Arg0 _r28;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28);
    typedef ClassType class_type;
    enum { arg_size=29 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg29 _r0;
    typedef Arg28 _r1;
    typedef Arg27 _r2;
    typedef Arg26 _r3;
    typedef Arg25 _r4;
    typedef Arg24 _r5;
    typedef Arg23 _r6;
    typedef Arg22 _r7;
    typedef Arg21 _r8;
    typedef Arg20 _r9;
    typedef Arg19 _r10;
    typedef Arg18 _r11;
    typedef Arg17 _r12;
    typedef Arg16 _r13;
    typedef Arg15 _r14;
    typedef Arg14 _r15;
    typedef Arg13 _r16;
    typedef Arg12 _r17;
    typedef Arg11 _r18;
    typedef Arg10 _r19;
    typedef Arg9 _r20;
    typedef Arg8 _r21;
    typedef Arg7 _r22;
    typedef Arg6 _r23;
    typedef Arg5 _r24;
    typedef Arg4 _r25;
    typedef Arg3 _r26;
    typedef Arg2 _r27;
    typedef Arg1 _r28;
    typedef Arg0 _r29;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    enum { arg_size=30 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg29 _r0;
    typedef Arg28 _r1;
    typedef Arg27 _r2;
    typedef Arg26 _r3;
    typedef Arg25 _r4;
    typedef Arg24 _r5;
    typedef Arg23 _r6;
    typedef Arg22 _r7;
    typedef Arg21 _r8;
    typedef Arg20 _r9;
    typedef Arg19 _r10;
    typedef Arg18 _r11;
    typedef Arg17 _r12;
    typedef Arg16 _r13;
    typedef Arg15 _r14;
    typedef Arg14 _r15;
    typedef Arg13 _r16;
    typedef Arg12 _r17;
    typedef Arg11 _r18;
    typedef Arg10 _r19;
    typedef Arg9 _r20;
    typedef Arg8 _r21;
    typedef Arg7 _r22;
    typedef Arg6 _r23;
    typedef Arg5 _r24;
    typedef Arg4 _r25;
    typedef Arg3 _r26;
    typedef Arg2 _r27;
    typedef Arg1 _r28;
    typedef Arg0 _r29;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    enum { arg_size=30 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg29 _r0;
    typedef Arg28 _r1;
    typedef Arg27 _r2;
    typedef Arg26 _r3;
    typedef Arg25 _r4;
    typedef Arg24 _r5;
    typedef Arg23 _r6;
    typedef Arg22 _r7;
    typedef Arg21 _r8;
    typedef Arg20 _r9;
    typedef Arg19 _r10;
    typedef Arg18 _r11;
    typedef Arg17 _r12;
    typedef Arg16 _r13;
    typedef Arg15 _r14;
    typedef Arg14 _r15;
    typedef Arg13 _r16;
    typedef Arg12 _r17;
    typedef Arg11 _r18;
    typedef Arg10 _r19;
    typedef Arg9 _r20;
    typedef Arg8 _r21;
    typedef Arg7 _r22;
    typedef Arg6 _r23;
    typedef Arg5 _r24;
    typedef Arg4 _r25;
    typedef Arg3 _r26;
    typedef Arg2 _r27;
    typedef Arg1 _r28;
    typedef Arg0 _r29;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    typedef ClassType class_type;
    enum { arg_size=30 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg29 _r0;
    typedef Arg28 _r1;
    typedef Arg27 _r2;
    typedef Arg26 _r3;
    typedef Arg25 _r4;
    typedef Arg24 _r5;
    typedef Arg23 _r6;
    typedef Arg22 _r7;
    typedef Arg21 _r8;
    typedef Arg20 _r9;
    typedef Arg19 _r10;
    typedef Arg18 _r11;
    typedef Arg17 _r12;
    typedef Arg16 _r13;
    typedef Arg15 _r14;
    typedef Arg14 _r15;
    typedef Arg13 _r16;
    typedef Arg12 _r17;
    typedef Arg11 _r18;
    typedef Arg10 _r19;
    typedef Arg9 _r20;
    typedef Arg8 _r21;
    typedef Arg7 _r22;
    typedef Arg6 _r23;
    typedef Arg5 _r24;
    typedef Arg4 _r25;
    typedef Arg3 _r26;
    typedef Arg2 _r27;
    typedef Arg1 _r28;
    typedef Arg0 _r29;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29);
    typedef ClassType class_type;
    enum { arg_size=30 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg30 _r0;
    typedef Arg29 _r1;
    typedef Arg28 _r2;
    typedef Arg27 _r3;
    typedef Arg26 _r4;
    typedef Arg25 _r5;
    typedef Arg24 _r6;
    typedef Arg23 _r7;
    typedef Arg22 _r8;
    typedef Arg21 _r9;
    typedef Arg20 _r10;
    typedef Arg19 _r11;
    typedef Arg18 _r12;
    typedef Arg17 _r13;
    typedef Arg16 _r14;
    typedef Arg15 _r15;
    typedef Arg14 _r16;
    typedef Arg13 _r17;
    typedef Arg12 _r18;
    typedef Arg11 _r19;
    typedef Arg10 _r20;
    typedef Arg9 _r21;
    typedef Arg8 _r22;
    typedef Arg7 _r23;
    typedef Arg6 _r24;
    typedef Arg5 _r25;
    typedef Arg4 _r26;
    typedef Arg3 _r27;
    typedef Arg2 _r28;
    typedef Arg1 _r29;
    typedef Arg0 _r30;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    enum { arg_size=31 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg30 _r0;
    typedef Arg29 _r1;
    typedef Arg28 _r2;
    typedef Arg27 _r3;
    typedef Arg26 _r4;
    typedef Arg25 _r5;
    typedef Arg24 _r6;
    typedef Arg23 _r7;
    typedef Arg22 _r8;
    typedef Arg21 _r9;
    typedef Arg20 _r10;
    typedef Arg19 _r11;
    typedef Arg18 _r12;
    typedef Arg17 _r13;
    typedef Arg16 _r14;
    typedef Arg15 _r15;
    typedef Arg14 _r16;
    typedef Arg13 _r17;
    typedef Arg12 _r18;
    typedef Arg11 _r19;
    typedef Arg10 _r20;
    typedef Arg9 _r21;
    typedef Arg8 _r22;
    typedef Arg7 _r23;
    typedef Arg6 _r24;
    typedef Arg5 _r25;
    typedef Arg4 _r26;
    typedef Arg3 _r27;
    typedef Arg2 _r28;
    typedef Arg1 _r29;
    typedef Arg0 _r30;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    enum { arg_size=31 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg30 _r0;
    typedef Arg29 _r1;
    typedef Arg28 _r2;
    typedef Arg27 _r3;
    typedef Arg26 _r4;
    typedef Arg25 _r5;
    typedef Arg24 _r6;
    typedef Arg23 _r7;
    typedef Arg22 _r8;
    typedef Arg21 _r9;
    typedef Arg20 _r10;
    typedef Arg19 _r11;
    typedef Arg18 _r12;
    typedef Arg17 _r13;
    typedef Arg16 _r14;
    typedef Arg15 _r15;
    typedef Arg14 _r16;
    typedef Arg13 _r17;
    typedef Arg12 _r18;
    typedef Arg11 _r19;
    typedef Arg10 _r20;
    typedef Arg9 _r21;
    typedef Arg8 _r22;
    typedef Arg7 _r23;
    typedef Arg6 _r24;
    typedef Arg5 _r25;
    typedef Arg4 _r26;
    typedef Arg3 _r27;
    typedef Arg2 _r28;
    typedef Arg1 _r29;
    typedef Arg0 _r30;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    typedef ClassType class_type;
    enum { arg_size=31 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg30 _r0;
    typedef Arg29 _r1;
    typedef Arg28 _r2;
    typedef Arg27 _r3;
    typedef Arg26 _r4;
    typedef Arg25 _r5;
    typedef Arg24 _r6;
    typedef Arg23 _r7;
    typedef Arg22 _r8;
    typedef Arg21 _r9;
    typedef Arg20 _r10;
    typedef Arg19 _r11;
    typedef Arg18 _r12;
    typedef Arg17 _r13;
    typedef Arg16 _r14;
    typedef Arg15 _r15;
    typedef Arg14 _r16;
    typedef Arg13 _r17;
    typedef Arg12 _r18;
    typedef Arg11 _r19;
    typedef Arg10 _r20;
    typedef Arg9 _r21;
    typedef Arg8 _r22;
    typedef Arg7 _r23;
    typedef Arg6 _r24;
    typedef Arg5 _r25;
    typedef Arg4 _r26;
    typedef Arg3 _r27;
    typedef Arg2 _r28;
    typedef Arg1 _r29;
    typedef Arg0 _r30;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30);
    typedef ClassType class_type;
    enum { arg_size=31 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg31 _r0;
    typedef Arg30 _r1;
    typedef Arg29 _r2;
    typedef Arg28 _r3;
    typedef Arg27 _r4;
    typedef Arg26 _r5;
    typedef Arg25 _r6;
    typedef Arg24 _r7;
    typedef Arg23 _r8;
    typedef Arg22 _r9;
    typedef Arg21 _r10;
    typedef Arg20 _r11;
    typedef Arg19 _r12;
    typedef Arg18 _r13;
    typedef Arg17 _r14;
    typedef Arg16 _r15;
    typedef Arg15 _r16;
    typedef Arg14 _r17;
    typedef Arg13 _r18;
    typedef Arg12 _r19;
    typedef Arg11 _r20;
    typedef Arg10 _r21;
    typedef Arg9 _r22;
    typedef Arg8 _r23;
    typedef Arg7 _r24;
    typedef Arg6 _r25;
    typedef Arg5 _r26;
    typedef Arg4 _r27;
    typedef Arg3 _r28;
    typedef Arg2 _r29;
    typedef Arg1 _r30;
    typedef Arg0 _r31;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    enum { arg_size=32 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg31 _r0;
    typedef Arg30 _r1;
    typedef Arg29 _r2;
    typedef Arg28 _r3;
    typedef Arg27 _r4;
    typedef Arg26 _r5;
    typedef Arg25 _r6;
    typedef Arg24 _r7;
    typedef Arg23 _r8;
    typedef Arg22 _r9;
    typedef Arg21 _r10;
    typedef Arg20 _r11;
    typedef Arg19 _r12;
    typedef Arg18 _r13;
    typedef Arg17 _r14;
    typedef Arg16 _r15;
    typedef Arg15 _r16;
    typedef Arg14 _r17;
    typedef Arg13 _r18;
    typedef Arg12 _r19;
    typedef Arg11 _r20;
    typedef Arg10 _r21;
    typedef Arg9 _r22;
    typedef Arg8 _r23;
    typedef Arg7 _r24;
    typedef Arg6 _r25;
    typedef Arg5 _r26;
    typedef Arg4 _r27;
    typedef Arg3 _r28;
    typedef Arg2 _r29;
    typedef Arg1 _r30;
    typedef Arg0 _r31;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    enum { arg_size=32 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg31 _r0;
    typedef Arg30 _r1;
    typedef Arg29 _r2;
    typedef Arg28 _r3;
    typedef Arg27 _r4;
    typedef Arg26 _r5;
    typedef Arg25 _r6;
    typedef Arg24 _r7;
    typedef Arg23 _r8;
    typedef Arg22 _r9;
    typedef Arg21 _r10;
    typedef Arg20 _r11;
    typedef Arg19 _r12;
    typedef Arg18 _r13;
    typedef Arg17 _r14;
    typedef Arg16 _r15;
    typedef Arg15 _r16;
    typedef Arg14 _r17;
    typedef Arg13 _r18;
    typedef Arg12 _r19;
    typedef Arg11 _r20;
    typedef Arg10 _r21;
    typedef Arg9 _r22;
    typedef Arg8 _r23;
    typedef Arg7 _r24;
    typedef Arg6 _r25;
    typedef Arg5 _r26;
    typedef Arg4 _r27;
    typedef Arg3 _r28;
    typedef Arg2 _r29;
    typedef Arg1 _r30;
    typedef Arg0 _r31;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    typedef ClassType class_type;
    enum { arg_size=32 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg31 _r0;
    typedef Arg30 _r1;
    typedef Arg29 _r2;
    typedef Arg28 _r3;
    typedef Arg27 _r4;
    typedef Arg26 _r5;
    typedef Arg25 _r6;
    typedef Arg24 _r7;
    typedef Arg23 _r8;
    typedef Arg22 _r9;
    typedef Arg21 _r10;
    typedef Arg20 _r11;
    typedef Arg19 _r12;
    typedef Arg18 _r13;
    typedef Arg17 _r14;
    typedef Arg16 _r15;
    typedef Arg15 _r16;
    typedef Arg14 _r17;
    typedef Arg13 _r18;
    typedef Arg12 _r19;
    typedef Arg11 _r20;
    typedef Arg10 _r21;
    typedef Arg9 _r22;
    typedef Arg8 _r23;
    typedef Arg7 _r24;
    typedef Arg6 _r25;
    typedef Arg5 _r26;
    typedef Arg4 _r27;
    typedef Arg3 _r28;
    typedef Arg2 _r29;
    typedef Arg1 _r30;
    typedef Arg0 _r31;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31);
    typedef ClassType class_type;
    enum { arg_size=32 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg32 _r0;
    typedef Arg31 _r1;
    typedef Arg30 _r2;
    typedef Arg29 _r3;
    typedef Arg28 _r4;
    typedef Arg27 _r5;
    typedef Arg26 _r6;
    typedef Arg25 _r7;
    typedef Arg24 _r8;
    typedef Arg23 _r9;
    typedef Arg22 _r10;
    typedef Arg21 _r11;
    typedef Arg20 _r12;
    typedef Arg19 _r13;
    typedef Arg18 _r14;
    typedef Arg17 _r15;
    typedef Arg16 _r16;
    typedef Arg15 _r17;
    typedef Arg14 _r18;
    typedef Arg13 _r19;
    typedef Arg12 _r20;
    typedef Arg11 _r21;
    typedef Arg10 _r22;
    typedef Arg9 _r23;
    typedef Arg8 _r24;
    typedef Arg7 _r25;
    typedef Arg6 _r26;
    typedef Arg5 _r27;
    typedef Arg4 _r28;
    typedef Arg3 _r29;
    typedef Arg2 _r30;
    typedef Arg1 _r31;
    typedef Arg0 _r32;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    enum { arg_size=33 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg32 _r0;
    typedef Arg31 _r1;
    typedef Arg30 _r2;
    typedef Arg29 _r3;
    typedef Arg28 _r4;
    typedef Arg27 _r5;
    typedef Arg26 _r6;
    typedef Arg25 _r7;
    typedef Arg24 _r8;
    typedef Arg23 _r9;
    typedef Arg22 _r10;
    typedef Arg21 _r11;
    typedef Arg20 _r12;
    typedef Arg19 _r13;
    typedef Arg18 _r14;
    typedef Arg17 _r15;
    typedef Arg16 _r16;
    typedef Arg15 _r17;
    typedef Arg14 _r18;
    typedef Arg13 _r19;
    typedef Arg12 _r20;
    typedef Arg11 _r21;
    typedef Arg10 _r22;
    typedef Arg9 _r23;
    typedef Arg8 _r24;
    typedef Arg7 _r25;
    typedef Arg6 _r26;
    typedef Arg5 _r27;
    typedef Arg4 _r28;
    typedef Arg3 _r29;
    typedef Arg2 _r30;
    typedef Arg1 _r31;
    typedef Arg0 _r32;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    enum { arg_size=33 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg32 _r0;
    typedef Arg31 _r1;
    typedef Arg30 _r2;
    typedef Arg29 _r3;
    typedef Arg28 _r4;
    typedef Arg27 _r5;
    typedef Arg26 _r6;
    typedef Arg25 _r7;
    typedef Arg24 _r8;
    typedef Arg23 _r9;
    typedef Arg22 _r10;
    typedef Arg21 _r11;
    typedef Arg20 _r12;
    typedef Arg19 _r13;
    typedef Arg18 _r14;
    typedef Arg17 _r15;
    typedef Arg16 _r16;
    typedef Arg15 _r17;
    typedef Arg14 _r18;
    typedef Arg13 _r19;
    typedef Arg12 _r20;
    typedef Arg11 _r21;
    typedef Arg10 _r22;
    typedef Arg9 _r23;
    typedef Arg8 _r24;
    typedef Arg7 _r25;
    typedef Arg6 _r26;
    typedef Arg5 _r27;
    typedef Arg4 _r28;
    typedef Arg3 _r29;
    typedef Arg2 _r30;
    typedef Arg1 _r31;
    typedef Arg0 _r32;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    typedef ClassType class_type;
    enum { arg_size=33 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg32 _r0;
    typedef Arg31 _r1;
    typedef Arg30 _r2;
    typedef Arg29 _r3;
    typedef Arg28 _r4;
    typedef Arg27 _r5;
    typedef Arg26 _r6;
    typedef Arg25 _r7;
    typedef Arg24 _r8;
    typedef Arg23 _r9;
    typedef Arg22 _r10;
    typedef Arg21 _r11;
    typedef Arg20 _r12;
    typedef Arg19 _r13;
    typedef Arg18 _r14;
    typedef Arg17 _r15;
    typedef Arg16 _r16;
    typedef Arg15 _r17;
    typedef Arg14 _r18;
    typedef Arg13 _r19;
    typedef Arg12 _r20;
    typedef Arg11 _r21;
    typedef Arg10 _r22;
    typedef Arg9 _r23;
    typedef Arg8 _r24;
    typedef Arg7 _r25;
    typedef Arg6 _r26;
    typedef Arg5 _r27;
    typedef Arg4 _r28;
    typedef Arg3 _r29;
    typedef Arg2 _r30;
    typedef Arg1 _r31;
    typedef Arg0 _r32;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32);
    typedef ClassType class_type;
    enum { arg_size=33 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg33 _r0;
    typedef Arg32 _r1;
    typedef Arg31 _r2;
    typedef Arg30 _r3;
    typedef Arg29 _r4;
    typedef Arg28 _r5;
    typedef Arg27 _r6;
    typedef Arg26 _r7;
    typedef Arg25 _r8;
    typedef Arg24 _r9;
    typedef Arg23 _r10;
    typedef Arg22 _r11;
    typedef Arg21 _r12;
    typedef Arg20 _r13;
    typedef Arg19 _r14;
    typedef Arg18 _r15;
    typedef Arg17 _r16;
    typedef Arg16 _r17;
    typedef Arg15 _r18;
    typedef Arg14 _r19;
    typedef Arg13 _r20;
    typedef Arg12 _r21;
    typedef Arg11 _r22;
    typedef Arg10 _r23;
    typedef Arg9 _r24;
    typedef Arg8 _r25;
    typedef Arg7 _r26;
    typedef Arg6 _r27;
    typedef Arg5 _r28;
    typedef Arg4 _r29;
    typedef Arg3 _r30;
    typedef Arg2 _r31;
    typedef Arg1 _r32;
    typedef Arg0 _r33;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    enum { arg_size=34 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg33 _r0;
    typedef Arg32 _r1;
    typedef Arg31 _r2;
    typedef Arg30 _r3;
    typedef Arg29 _r4;
    typedef Arg28 _r5;
    typedef Arg27 _r6;
    typedef Arg26 _r7;
    typedef Arg25 _r8;
    typedef Arg24 _r9;
    typedef Arg23 _r10;
    typedef Arg22 _r11;
    typedef Arg21 _r12;
    typedef Arg20 _r13;
    typedef Arg19 _r14;
    typedef Arg18 _r15;
    typedef Arg17 _r16;
    typedef Arg16 _r17;
    typedef Arg15 _r18;
    typedef Arg14 _r19;
    typedef Arg13 _r20;
    typedef Arg12 _r21;
    typedef Arg11 _r22;
    typedef Arg10 _r23;
    typedef Arg9 _r24;
    typedef Arg8 _r25;
    typedef Arg7 _r26;
    typedef Arg6 _r27;
    typedef Arg5 _r28;
    typedef Arg4 _r29;
    typedef Arg3 _r30;
    typedef Arg2 _r31;
    typedef Arg1 _r32;
    typedef Arg0 _r33;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    enum { arg_size=34 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg33 _r0;
    typedef Arg32 _r1;
    typedef Arg31 _r2;
    typedef Arg30 _r3;
    typedef Arg29 _r4;
    typedef Arg28 _r5;
    typedef Arg27 _r6;
    typedef Arg26 _r7;
    typedef Arg25 _r8;
    typedef Arg24 _r9;
    typedef Arg23 _r10;
    typedef Arg22 _r11;
    typedef Arg21 _r12;
    typedef Arg20 _r13;
    typedef Arg19 _r14;
    typedef Arg18 _r15;
    typedef Arg17 _r16;
    typedef Arg16 _r17;
    typedef Arg15 _r18;
    typedef Arg14 _r19;
    typedef Arg13 _r20;
    typedef Arg12 _r21;
    typedef Arg11 _r22;
    typedef Arg10 _r23;
    typedef Arg9 _r24;
    typedef Arg8 _r25;
    typedef Arg7 _r26;
    typedef Arg6 _r27;
    typedef Arg5 _r28;
    typedef Arg4 _r29;
    typedef Arg3 _r30;
    typedef Arg2 _r31;
    typedef Arg1 _r32;
    typedef Arg0 _r33;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    typedef ClassType class_type;
    enum { arg_size=34 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg33 _r0;
    typedef Arg32 _r1;
    typedef Arg31 _r2;
    typedef Arg30 _r3;
    typedef Arg29 _r4;
    typedef Arg28 _r5;
    typedef Arg27 _r6;
    typedef Arg26 _r7;
    typedef Arg25 _r8;
    typedef Arg24 _r9;
    typedef Arg23 _r10;
    typedef Arg22 _r11;
    typedef Arg21 _r12;
    typedef Arg20 _r13;
    typedef Arg19 _r14;
    typedef Arg18 _r15;
    typedef Arg17 _r16;
    typedef Arg16 _r17;
    typedef Arg15 _r18;
    typedef Arg14 _r19;
    typedef Arg13 _r20;
    typedef Arg12 _r21;
    typedef Arg11 _r22;
    typedef Arg10 _r23;
    typedef Arg9 _r24;
    typedef Arg8 _r25;
    typedef Arg7 _r26;
    typedef Arg6 _r27;
    typedef Arg5 _r28;
    typedef Arg4 _r29;
    typedef Arg3 _r30;
    typedef Arg2 _r31;
    typedef Arg1 _r32;
    typedef Arg0 _r33;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33);
    typedef ClassType class_type;
    enum { arg_size=34 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg34 _r0;
    typedef Arg33 _r1;
    typedef Arg32 _r2;
    typedef Arg31 _r3;
    typedef Arg30 _r4;
    typedef Arg29 _r5;
    typedef Arg28 _r6;
    typedef Arg27 _r7;
    typedef Arg26 _r8;
    typedef Arg25 _r9;
    typedef Arg24 _r10;
    typedef Arg23 _r11;
    typedef Arg22 _r12;
    typedef Arg21 _r13;
    typedef Arg20 _r14;
    typedef Arg19 _r15;
    typedef Arg18 _r16;
    typedef Arg17 _r17;
    typedef Arg16 _r18;
    typedef Arg15 _r19;
    typedef Arg14 _r20;
    typedef Arg13 _r21;
    typedef Arg12 _r22;
    typedef Arg11 _r23;
    typedef Arg10 _r24;
    typedef Arg9 _r25;
    typedef Arg8 _r26;
    typedef Arg7 _r27;
    typedef Arg6 _r28;
    typedef Arg5 _r29;
    typedef Arg4 _r30;
    typedef Arg3 _r31;
    typedef Arg2 _r32;
    typedef Arg1 _r33;
    typedef Arg0 _r34;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    enum { arg_size=35 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg34 _r0;
    typedef Arg33 _r1;
    typedef Arg32 _r2;
    typedef Arg31 _r3;
    typedef Arg30 _r4;
    typedef Arg29 _r5;
    typedef Arg28 _r6;
    typedef Arg27 _r7;
    typedef Arg26 _r8;
    typedef Arg25 _r9;
    typedef Arg24 _r10;
    typedef Arg23 _r11;
    typedef Arg22 _r12;
    typedef Arg21 _r13;
    typedef Arg20 _r14;
    typedef Arg19 _r15;
    typedef Arg18 _r16;
    typedef Arg17 _r17;
    typedef Arg16 _r18;
    typedef Arg15 _r19;
    typedef Arg14 _r20;
    typedef Arg13 _r21;
    typedef Arg12 _r22;
    typedef Arg11 _r23;
    typedef Arg10 _r24;
    typedef Arg9 _r25;
    typedef Arg8 _r26;
    typedef Arg7 _r27;
    typedef Arg6 _r28;
    typedef Arg5 _r29;
    typedef Arg4 _r30;
    typedef Arg3 _r31;
    typedef Arg2 _r32;
    typedef Arg1 _r33;
    typedef Arg0 _r34;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    enum { arg_size=35 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg34 _r0;
    typedef Arg33 _r1;
    typedef Arg32 _r2;
    typedef Arg31 _r3;
    typedef Arg30 _r4;
    typedef Arg29 _r5;
    typedef Arg28 _r6;
    typedef Arg27 _r7;
    typedef Arg26 _r8;
    typedef Arg25 _r9;
    typedef Arg24 _r10;
    typedef Arg23 _r11;
    typedef Arg22 _r12;
    typedef Arg21 _r13;
    typedef Arg20 _r14;
    typedef Arg19 _r15;
    typedef Arg18 _r16;
    typedef Arg17 _r17;
    typedef Arg16 _r18;
    typedef Arg15 _r19;
    typedef Arg14 _r20;
    typedef Arg13 _r21;
    typedef Arg12 _r22;
    typedef Arg11 _r23;
    typedef Arg10 _r24;
    typedef Arg9 _r25;
    typedef Arg8 _r26;
    typedef Arg7 _r27;
    typedef Arg6 _r28;
    typedef Arg5 _r29;
    typedef Arg4 _r30;
    typedef Arg3 _r31;
    typedef Arg2 _r32;
    typedef Arg1 _r33;
    typedef Arg0 _r34;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    typedef ClassType class_type;
    enum { arg_size=35 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg34 _r0;
    typedef Arg33 _r1;
    typedef Arg32 _r2;
    typedef Arg31 _r3;
    typedef Arg30 _r4;
    typedef Arg29 _r5;
    typedef Arg28 _r6;
    typedef Arg27 _r7;
    typedef Arg26 _r8;
    typedef Arg25 _r9;
    typedef Arg24 _r10;
    typedef Arg23 _r11;
    typedef Arg22 _r12;
    typedef Arg21 _r13;
    typedef Arg20 _r14;
    typedef Arg19 _r15;
    typedef Arg18 _r16;
    typedef Arg17 _r17;
    typedef Arg16 _r18;
    typedef Arg15 _r19;
    typedef Arg14 _r20;
    typedef Arg13 _r21;
    typedef Arg12 _r22;
    typedef Arg11 _r23;
    typedef Arg10 _r24;
    typedef Arg9 _r25;
    typedef Arg8 _r26;
    typedef Arg7 _r27;
    typedef Arg6 _r28;
    typedef Arg5 _r29;
    typedef Arg4 _r30;
    typedef Arg3 _r31;
    typedef Arg2 _r32;
    typedef Arg1 _r33;
    typedef Arg0 _r34;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34);
    typedef ClassType class_type;
    enum { arg_size=35 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34,
    typename Arg35
>
class FunctionType<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34,
    Arg35)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg35 _35;
    typedef Arg35 _r0;
    typedef Arg34 _r1;
    typedef Arg33 _r2;
    typedef Arg32 _r3;
    typedef Arg31 _r4;
    typedef Arg30 _r5;
    typedef Arg29 _r6;
    typedef Arg28 _r7;
    typedef Arg27 _r8;
    typedef Arg26 _r9;
    typedef Arg25 _r10;
    typedef Arg24 _r11;
    typedef Arg23 _r12;
    typedef Arg22 _r13;
    typedef Arg21 _r14;
    typedef Arg20 _r15;
    typedef Arg19 _r16;
    typedef Arg18 _r17;
    typedef Arg17 _r18;
    typedef Arg16 _r19;
    typedef Arg15 _r20;
    typedef Arg14 _r21;
    typedef Arg13 _r22;
    typedef Arg12 _r23;
    typedef Arg11 _r24;
    typedef Arg10 _r25;
    typedef Arg9 _r26;
    typedef Arg8 _r27;
    typedef Arg7 _r28;
    typedef Arg6 _r29;
    typedef Arg5 _r30;
    typedef Arg4 _r31;
    typedef Arg3 _r32;
    typedef Arg2 _r33;
    typedef Arg1 _r34;
    typedef Arg0 _r35;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    enum { arg_size=36 };
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34,
    typename Arg35
>
class FunctionType<std::function<ReturnType(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34,
    Arg35)>>: public FunctionType<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35)>
{
public:
};

template<
    typename ReturnType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34,
    typename Arg35
>
class FunctionType<ReturnType(*)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34,
    Arg35)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg35 _35;
    typedef Arg35 _r0;
    typedef Arg34 _r1;
    typedef Arg33 _r2;
    typedef Arg32 _r3;
    typedef Arg31 _r4;
    typedef Arg30 _r5;
    typedef Arg29 _r6;
    typedef Arg28 _r7;
    typedef Arg27 _r8;
    typedef Arg26 _r9;
    typedef Arg25 _r10;
    typedef Arg24 _r11;
    typedef Arg23 _r12;
    typedef Arg22 _r13;
    typedef Arg21 _r14;
    typedef Arg20 _r15;
    typedef Arg19 _r16;
    typedef Arg18 _r17;
    typedef Arg17 _r18;
    typedef Arg16 _r19;
    typedef Arg15 _r20;
    typedef Arg14 _r21;
    typedef Arg13 _r22;
    typedef Arg12 _r23;
    typedef Arg11 _r24;
    typedef Arg10 _r25;
    typedef Arg9 _r26;
    typedef Arg8 _r27;
    typedef Arg7 _r28;
    typedef Arg6 _r29;
    typedef Arg5 _r30;
    typedef Arg4 _r31;
    typedef Arg3 _r32;
    typedef Arg2 _r33;
    typedef Arg1 _r34;
    typedef Arg0 _r35;
    typedef ReturnType(*function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    typedef std::function<ReturnType(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35)>stl_function_type;
    typedef ReturnType(std_function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    enum { arg_size=36 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34,
    typename Arg35
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34,
    Arg35)> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg35 _35;
    typedef Arg35 _r0;
    typedef Arg34 _r1;
    typedef Arg33 _r2;
    typedef Arg32 _r3;
    typedef Arg31 _r4;
    typedef Arg30 _r5;
    typedef Arg29 _r6;
    typedef Arg28 _r7;
    typedef Arg27 _r8;
    typedef Arg26 _r9;
    typedef Arg25 _r10;
    typedef Arg24 _r11;
    typedef Arg23 _r12;
    typedef Arg22 _r13;
    typedef Arg21 _r14;
    typedef Arg20 _r15;
    typedef Arg19 _r16;
    typedef Arg18 _r17;
    typedef Arg17 _r18;
    typedef Arg16 _r19;
    typedef Arg15 _r20;
    typedef Arg14 _r21;
    typedef Arg13 _r22;
    typedef Arg12 _r23;
    typedef Arg11 _r24;
    typedef Arg10 _r25;
    typedef Arg9 _r26;
    typedef Arg8 _r27;
    typedef Arg7 _r28;
    typedef Arg6 _r29;
    typedef Arg5 _r30;
    typedef Arg4 _r31;
    typedef Arg3 _r32;
    typedef Arg2 _r33;
    typedef Arg1 _r34;
    typedef Arg0 _r35;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    typedef std::function<ReturnType(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35)>stl_function_type;
    typedef ReturnType(std_function_type)(
        ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    typedef ClassType class_type;
    enum { arg_size=36 };
};

template<
    typename ReturnType,
    typename ClassType,
    typename Arg0,
    typename Arg1,
    typename Arg2,
    typename Arg3,
    typename Arg4,
    typename Arg5,
    typename Arg6,
    typename Arg7,
    typename Arg8,
    typename Arg9,
    typename Arg10,
    typename Arg11,
    typename Arg12,
    typename Arg13,
    typename Arg14,
    typename Arg15,
    typename Arg16,
    typename Arg17,
    typename Arg18,
    typename Arg19,
    typename Arg20,
    typename Arg21,
    typename Arg22,
    typename Arg23,
    typename Arg24,
    typename Arg25,
    typename Arg26,
    typename Arg27,
    typename Arg28,
    typename Arg29,
    typename Arg30,
    typename Arg31,
    typename Arg32,
    typename Arg33,
    typename Arg34,
    typename Arg35
>
class FunctionType<ReturnType(ClassType:: *)(
    Arg0,
    Arg1,
    Arg2,
    Arg3,
    Arg4,
    Arg5,
    Arg6,
    Arg7,
    Arg8,
    Arg9,
    Arg10,
    Arg11,
    Arg12,
    Arg13,
    Arg14,
    Arg15,
    Arg16,
    Arg17,
    Arg18,
    Arg19,
    Arg20,
    Arg21,
    Arg22,
    Arg23,
    Arg24,
    Arg25,
    Arg26,
    Arg27,
    Arg28,
    Arg29,
    Arg30,
    Arg31,
    Arg32,
    Arg33,
    Arg34,
    Arg35) const> {
public:
    typedef ReturnType return_type;
    typedef Arg0 _0;
    typedef Arg1 _1;
    typedef Arg2 _2;
    typedef Arg3 _3;
    typedef Arg4 _4;
    typedef Arg5 _5;
    typedef Arg6 _6;
    typedef Arg7 _7;
    typedef Arg8 _8;
    typedef Arg9 _9;
    typedef Arg10 _10;
    typedef Arg11 _11;
    typedef Arg12 _12;
    typedef Arg13 _13;
    typedef Arg14 _14;
    typedef Arg15 _15;
    typedef Arg16 _16;
    typedef Arg17 _17;
    typedef Arg18 _18;
    typedef Arg19 _19;
    typedef Arg20 _20;
    typedef Arg21 _21;
    typedef Arg22 _22;
    typedef Arg23 _23;
    typedef Arg24 _24;
    typedef Arg25 _25;
    typedef Arg26 _26;
    typedef Arg27 _27;
    typedef Arg28 _28;
    typedef Arg29 _29;
    typedef Arg30 _30;
    typedef Arg31 _31;
    typedef Arg32 _32;
    typedef Arg33 _33;
    typedef Arg34 _34;
    typedef Arg35 _35;
    typedef Arg35 _r0;
    typedef Arg34 _r1;
    typedef Arg33 _r2;
    typedef Arg32 _r3;
    typedef Arg31 _r4;
    typedef Arg30 _r5;
    typedef Arg29 _r6;
    typedef Arg28 _r7;
    typedef Arg27 _r8;
    typedef Arg26 _r9;
    typedef Arg25 _r10;
    typedef Arg24 _r11;
    typedef Arg23 _r12;
    typedef Arg22 _r13;
    typedef Arg21 _r14;
    typedef Arg20 _r15;
    typedef Arg19 _r16;
    typedef Arg18 _r17;
    typedef Arg17 _r18;
    typedef Arg16 _r19;
    typedef Arg15 _r20;
    typedef Arg14 _r21;
    typedef Arg13 _r22;
    typedef Arg12 _r23;
    typedef Arg11 _r24;
    typedef Arg10 _r25;
    typedef Arg9 _r26;
    typedef Arg8 _r27;
    typedef Arg7 _r28;
    typedef Arg6 _r29;
    typedef Arg5 _r30;
    typedef Arg4 _r31;
    typedef Arg3 _r32;
    typedef Arg2 _r33;
    typedef Arg1 _r34;
    typedef Arg0 _r35;
    typedef ReturnType(ClassType::* function_type)(
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35) const;
    typedef std::function<ReturnType(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35)>stl_function_type;
    typedef ReturnType(std_function_type)(
        const ClassType *,
        Arg0,
        Arg1,
        Arg2,
        Arg3,
        Arg4,
        Arg5,
        Arg6,
        Arg7,
        Arg8,
        Arg9,
        Arg10,
        Arg11,
        Arg12,
        Arg13,
        Arg14,
        Arg15,
        Arg16,
        Arg17,
        Arg18,
        Arg19,
        Arg20,
        Arg21,
        Arg22,
        Arg23,
        Arg24,
        Arg25,
        Arg26,
        Arg27,
        Arg28,
        Arg29,
        Arg30,
        Arg31,
        Arg32,
        Arg33,
        Arg34,
        Arg35);
    typedef ClassType class_type;
    enum { arg_size=36 };
};

}

namespace cct {

template<typename T>
class func
:public FunctionType<T>::stl_function_type,
 public FunctionType<T>{
};

}

#endif
