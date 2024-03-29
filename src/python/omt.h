/*
* @file: python/omt.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/inc.h>

/*!
* Python export of the OMT module
* @return OMT module object
*/
extern "C" PyObject * pybind11_init_impl_omt();
