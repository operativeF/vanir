#!/usr/bin/python

from dataclasses import dataclass

@dataclass
class Prefix:
    Name: str
    Symbol: str
    Factor: int
    Value: int

@dataclass
class Unit:
    Name: str
    Type: str
    Symbol: str
    Equation_Symbol: str
    Base_Numer: str
    Base_Denom: str
    Impl_Numer: str
    Impl_Denom: str
    Desc: str