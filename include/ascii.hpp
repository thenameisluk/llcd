#pragma once
inline bool characters[][5][5] = {
    {{false,false,false,false,false},//spacja
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},

    {{false,false,true,false,false},//!
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//"
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    {{false,true,false,true,false},//#
    {true,true,true,true,true},
    {false,true,false,true,false},
    {true,true,true,true,true},
    {false,true,false,true,false}},
    
    {{false,true,true,true,false},//$
    {true,false,true,false,false},
    {false,true,true,true,false},
    {false,false,true,false,true},
    {false,true,true,true,false}},
    
    {{true,false,false,false,true},//%
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false},
    {true,false,false,false,true}},
    
    {{false,false,true,false,false},//&
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,true,false,true,false},
    {false,false,true,false,true}},
    
    {{false,false,true,false,false},//'
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    {{false,false,true,false,false},//(
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//)
    {false,false,false,true,false},
    {false,false,false,true,false},
    {false,false,false,true,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//*
    {false,true,true,true,false},
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    {{false,false,false,false,false},//+
    {false,false,true,false,false},
    {false,true,true,true,false},
    {false,false,true,false,false},
    {false,false,false,false,false}},
    
    {{false,false,false,false,false},//,
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,false,false,false},//-
    {false,false,false,false,false},
    {false,true,true,true,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    {{false,false,false,false,false},//.
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false}},
    
    {{false,false,false,true,false},///
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,true,false,false,false}},
    
    {{false,false,true,false,false},//0
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//1
    {false,true,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//2
    {false,true,false,true,false},
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,true,true,true,false}},
    
    {{false,true,true,false,false},//3
    {false,false,false,true,false},
    {false,true,true,false,false},
    {false,false,false,true,false},
    {false,true,true,false,false}},
    
    {{false,false,false,true,false},//4
    {false,false,true,true,false},
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,false,false,true,false}},
    
    {{false,true,true,true,false},//5
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,false,true,true,false}},
    
    {{false,false,true,true,false},//6
    {false,true,false,false,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,true,true,false},//7
    {false,false,false,true,false},
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//8
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//9
    {false,true,false,true,false},
    {false,false,true,true,false},
    {false,false,false,true,false},
    {false,true,true,false,false}},
    
    {{false,false,false,false,false},//:
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false},
    {false,false,false,false,false}},
    
    {{false,false,false,false,false},//;
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,false,true,false},//<
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false}},
    
    {{false,false,false,false,false},//=
    {false,true,true,true,false},
    {false,false,false,false,false},
    {false,true,true,true,false},
    {false,false,false,false,false}},
    
    {{false,false,false,true,false},//>
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false}},
    
    {{false,true,true,false,false},//?
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//@
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//a
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,true,false,false},//b
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,true,false,false}},
    
    {{false,false,true,true,false},//c
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,false,true,true,false}},
    
    {{false,true,true,false,false},//d
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,false,false}},
    
    {{false,true,true,true,false},//e
    {false,true,false,false,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,true,true,false}},
    
    {{false,true,true,true,false},//f
    {false,true,false,false,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false}},
    
    {{false,false,true,true,false},//g
    {false,true,false,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//h
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//i
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//j
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,true,false,false,false}},
    
    {{false,true,false,true,false},//k
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//l
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,true,false}},
    
    {{false,true,false,true,false},//m
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//n
    {false,true,true,true,false},
    {false,true,true,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//o
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,true,false,false},//p
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false}},
    
    {{false,false,true,false,false},//q
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,true,false}},
    
    {{false,true,true,false,false},//r
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,true,false},//s
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false},
    {false,true,true,false,false}},
    
    {{false,true,true,true,false},//t
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//u
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,true,false}},
    
    {{false,true,false,true,false},//v
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//w
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//x
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//y
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,true,true,true,false},//z
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,true,true,true,false}},
    
    {{false,true,true,false,false},//[
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,true,true,false,false}},
    
    {{false,true,false,false,false},//\-
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false}},
    
    {{false,false,true,true,false},//]
    {false,false,false,true,false},
    {false,false,false,true,false},
    {false,false,false,true,false},
    {false,false,true,true,false}},
    
    {{false,false,true,false,false},//^
    {false,true,false,true,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    {{false,false,false,false,false},//_
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,true,true,true,false}},
    
    {{false,true,false,false,false},//`
    {false,false,true,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
    
    //repeat for small letters

    {{false,false,true,false,false},//a
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,true,false,false},//b
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,true,false,false}},
    
    {{false,false,true,true,false},//c
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false},
    {false,false,true,true,false}},
    
    {{false,true,true,false,false},//d
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,false,false}},
    
    {{false,true,true,true,false},//e
    {false,true,false,false,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,true,true,false}},
    
    {{false,true,true,true,false},//f
    {false,true,false,false,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false}},
    
    {{false,false,true,true,false},//g
    {false,true,false,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//h
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//i
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,false,true,false,false},//j
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,true,false,false,false}},
    
    {{false,true,false,true,false},//k
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//l
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,true,false}},
    
    {{false,true,false,true,false},//m
    {false,true,true,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//n
    {false,true,true,true,false},
    {false,true,true,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,false,false},//o
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,true,false,false},//p
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,false,false},
    {false,true,false,false,false}},
    
    {{false,false,true,false,false},//q
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,true,false}},
    
    {{false,true,true,false,false},//r
    {false,true,false,true,false},
    {false,true,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,false,true,true,false},//s
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,false,false,true,false},
    {false,true,true,false,false}},
    
    {{false,true,true,true,false},//t
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//u
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,true,false}},
    
    {{false,true,false,true,false},//v
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//w
    {false,true,false,true,false},
    {false,true,false,true,false},
    {false,true,true,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//x
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,true,false,true,false},
    {false,true,false,true,false}},
    
    {{false,true,false,true,false},//y
    {false,true,false,true,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false}},
    
    {{false,true,true,true,false},//z
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,true,true,true,false}},
    
    {{false,false,true,false,false},//{
    {false,true,false,false,false},
    {false,false,true,false,false},
    {false,true,false,false,false},
    {false,false,true,false,false}},
    
    {{false,false,false,false,false},//|
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,true,false,false},
    {false,false,false,false,false}},
    
    {{false,false,true,false,false},//}
    {false,false,false,true,false},
    {false,false,true,false,false},
    {false,false,false,true,false},
    {false,false,true,false,false}},
    
    {{false,true,false,true,false},//~
    {false,false,true,false,true},
    {false,false,false,false,false},
    {false,false,false,false,false},
    {false,false,false,false,false}},
};