#if !defined(CHECK__ARGS__HPP__CCT)
#define CHECK__ARGS__HPP__CCT
namespace cct{


template<unsigned int N=0, typename T0>
void checkArgs(const T0 & t0) { if ( t0 ) { return; } else { throw N; } }

template< unsigned int N = 0, typename A0 , typename ... Args >
void checkArgs( const A0 & a0 , const Args & ... args ) {
    {checkArgs<N>(a0); }return checkArgs<N+1>(  args ...  );
}

#if !defined check_args
#define check_args( ... ) checkArgs( __VA_ARGS__ )
#endif

}

#endif
