#if !defined(CHECK__ARGS__HPP__CCT)
#define CHECK__ARGS__HPP__CCT

namespace cct{

template<typename ErrorType>
void check_args() {}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0
    ) {
    if (a0) { }else { throw ErrorType(i0); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31,
    typename ArgType32,typename InfoType32
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31,
    const ArgType32 & a32,const InfoType32& i32
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
    if (a32) { }else { throw ErrorType(i32); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31,
    typename ArgType32,typename InfoType32,
    typename ArgType33,typename InfoType33
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31,
    const ArgType32 & a32,const InfoType32& i32,
    const ArgType33 & a33,const InfoType33& i33
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
    if (a32) { }else { throw ErrorType(i32); }
    if (a33) { }else { throw ErrorType(i33); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31,
    typename ArgType32,typename InfoType32,
    typename ArgType33,typename InfoType33,
    typename ArgType34,typename InfoType34
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31,
    const ArgType32 & a32,const InfoType32& i32,
    const ArgType33 & a33,const InfoType33& i33,
    const ArgType34 & a34,const InfoType34& i34
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
    if (a32) { }else { throw ErrorType(i32); }
    if (a33) { }else { throw ErrorType(i33); }
    if (a34) { }else { throw ErrorType(i34); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31,
    typename ArgType32,typename InfoType32,
    typename ArgType33,typename InfoType33,
    typename ArgType34,typename InfoType34,
    typename ArgType35,typename InfoType35
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31,
    const ArgType32 & a32,const InfoType32& i32,
    const ArgType33 & a33,const InfoType33& i33,
    const ArgType34 & a34,const InfoType34& i34,
    const ArgType35 & a35,const InfoType35& i35
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
    if (a32) { }else { throw ErrorType(i32); }
    if (a33) { }else { throw ErrorType(i33); }
    if (a34) { }else { throw ErrorType(i34); }
    if (a35) { }else { throw ErrorType(i35); }
}

template <
    typename ErrorType,
    typename ArgType0,typename InfoType0,
    typename ArgType1,typename InfoType1,
    typename ArgType2,typename InfoType2,
    typename ArgType3,typename InfoType3,
    typename ArgType4,typename InfoType4,
    typename ArgType5,typename InfoType5,
    typename ArgType6,typename InfoType6,
    typename ArgType7,typename InfoType7,
    typename ArgType8,typename InfoType8,
    typename ArgType9,typename InfoType9,
    typename ArgType10,typename InfoType10,
    typename ArgType11,typename InfoType11,
    typename ArgType12,typename InfoType12,
    typename ArgType13,typename InfoType13,
    typename ArgType14,typename InfoType14,
    typename ArgType15,typename InfoType15,
    typename ArgType16,typename InfoType16,
    typename ArgType17,typename InfoType17,
    typename ArgType18,typename InfoType18,
    typename ArgType19,typename InfoType19,
    typename ArgType20,typename InfoType20,
    typename ArgType21,typename InfoType21,
    typename ArgType22,typename InfoType22,
    typename ArgType23,typename InfoType23,
    typename ArgType24,typename InfoType24,
    typename ArgType25,typename InfoType25,
    typename ArgType26,typename InfoType26,
    typename ArgType27,typename InfoType27,
    typename ArgType28,typename InfoType28,
    typename ArgType29,typename InfoType29,
    typename ArgType30,typename InfoType30,
    typename ArgType31,typename InfoType31,
    typename ArgType32,typename InfoType32,
    typename ArgType33,typename InfoType33,
    typename ArgType34,typename InfoType34,
    typename ArgType35,typename InfoType35,
    typename ... Args
>
void check_args(
    const ArgType0 & a0,const InfoType0& i0,
    const ArgType1 & a1,const InfoType1& i1,
    const ArgType2 & a2,const InfoType2& i2,
    const ArgType3 & a3,const InfoType3& i3,
    const ArgType4 & a4,const InfoType4& i4,
    const ArgType5 & a5,const InfoType5& i5,
    const ArgType6 & a6,const InfoType6& i6,
    const ArgType7 & a7,const InfoType7& i7,
    const ArgType8 & a8,const InfoType8& i8,
    const ArgType9 & a9,const InfoType9& i9,
    const ArgType10 & a10,const InfoType10& i10,
    const ArgType11 & a11,const InfoType11& i11,
    const ArgType12 & a12,const InfoType12& i12,
    const ArgType13 & a13,const InfoType13& i13,
    const ArgType14 & a14,const InfoType14& i14,
    const ArgType15 & a15,const InfoType15& i15,
    const ArgType16 & a16,const InfoType16& i16,
    const ArgType17 & a17,const InfoType17& i17,
    const ArgType18 & a18,const InfoType18& i18,
    const ArgType19 & a19,const InfoType19& i19,
    const ArgType20 & a20,const InfoType20& i20,
    const ArgType21 & a21,const InfoType21& i21,
    const ArgType22 & a22,const InfoType22& i22,
    const ArgType23 & a23,const InfoType23& i23,
    const ArgType24 & a24,const InfoType24& i24,
    const ArgType25 & a25,const InfoType25& i25,
    const ArgType26 & a26,const InfoType26& i26,
    const ArgType27 & a27,const InfoType27& i27,
    const ArgType28 & a28,const InfoType28& i28,
    const ArgType29 & a29,const InfoType29& i29,
    const ArgType30 & a30,const InfoType30& i30,
    const ArgType31 & a31,const InfoType31& i31,
    const ArgType32 & a32,const InfoType32& i32,
    const ArgType33 & a33,const InfoType33& i33,
    const ArgType34 & a34,const InfoType34& i34,
    const ArgType35 & a35,const InfoType35& i35,
    const Args & ... args
    ) {
    if (a0) { }else { throw ErrorType(i0); }
    if (a1) { }else { throw ErrorType(i1); }
    if (a2) { }else { throw ErrorType(i2); }
    if (a3) { }else { throw ErrorType(i3); }
    if (a4) { }else { throw ErrorType(i4); }
    if (a5) { }else { throw ErrorType(i5); }
    if (a6) { }else { throw ErrorType(i6); }
    if (a7) { }else { throw ErrorType(i7); }
    if (a8) { }else { throw ErrorType(i8); }
    if (a9) { }else { throw ErrorType(i9); }
    if (a10) { }else { throw ErrorType(i10); }
    if (a11) { }else { throw ErrorType(i11); }
    if (a12) { }else { throw ErrorType(i12); }
    if (a13) { }else { throw ErrorType(i13); }
    if (a14) { }else { throw ErrorType(i14); }
    if (a15) { }else { throw ErrorType(i15); }
    if (a16) { }else { throw ErrorType(i16); }
    if (a17) { }else { throw ErrorType(i17); }
    if (a18) { }else { throw ErrorType(i18); }
    if (a19) { }else { throw ErrorType(i19); }
    if (a20) { }else { throw ErrorType(i20); }
    if (a21) { }else { throw ErrorType(i21); }
    if (a22) { }else { throw ErrorType(i22); }
    if (a23) { }else { throw ErrorType(i23); }
    if (a24) { }else { throw ErrorType(i24); }
    if (a25) { }else { throw ErrorType(i25); }
    if (a26) { }else { throw ErrorType(i26); }
    if (a27) { }else { throw ErrorType(i27); }
    if (a28) { }else { throw ErrorType(i28); }
    if (a29) { }else { throw ErrorType(i29); }
    if (a30) { }else { throw ErrorType(i30); }
    if (a31) { }else { throw ErrorType(i31); }
    if (a32) { }else { throw ErrorType(i32); }
    if (a33) { }else { throw ErrorType(i33); }
    if (a34) { }else { throw ErrorType(i34); }
    if (a35) { }else { throw ErrorType(i35); }
    check_args<ErrorType>( args... );
}

}

#endif

