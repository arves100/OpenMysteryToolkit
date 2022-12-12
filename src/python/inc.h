/*
* @file: python/inc.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

// no autolink but keep it shared
#define MS_NO_COREDLL 1
#define Py_ENABLE_SHARED 1
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
