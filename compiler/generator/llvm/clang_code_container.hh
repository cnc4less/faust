/************************************************************************
 ************************************************************************
    FAUST compiler
	Copyright (C) 2003-2004 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef _CLANG_CODE_CONTAINER_H
#define _CLANG_CODE_CONTAINER_H

#include "libfaust.h"
#include "cpp_code_container.hh"
#include "c_code_container.hh"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace llvm;

struct LLVMResult;

class ClangCodeContainer : public virtual CodeContainer {

    protected:
     
        LLVMResult* fResult;
        
        CodeContainer* fContainer;
        //std::stringstream fOut;
        std::ofstream fOut;
       
        LLVMContext& getContext();
   
    public:

        ClangCodeContainer(const string& name, int numInputs, int numOutputs);
        ClangCodeContainer(const string& name, int numInputs, int numOutputs, LLVMResult* result);
        virtual ~ClangCodeContainer();
      
        virtual LLVMResult* produceModule(Tree signals, const string& filename);
        
        virtual void produceInternal() { fContainer->produceClass(); }
    
        CodeContainer* createScalarContainer(const string& name, int sub_container_type);

        static CodeContainer* createContainer(const string& name, int numInputs, int numOutputs);

};

#endif