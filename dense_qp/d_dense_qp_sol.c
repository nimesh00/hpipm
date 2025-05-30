/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High-Performance Interior Point Method.                                                *
* Copyright (C) 2019 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* The 2-Clause BSD License                                                                        *
*                                                                                                 *
* Redistribution and use in source and binary forms, with or without                              *
* modification, are permitted provided that the following conditions are met:                     *
*                                                                                                 *
* 1. Redistributions of source code must retain the above copyright notice, this                  *
*    list of conditions and the following disclaimer.                                             *
* 2. Redistributions in binary form must reproduce the above copyright notice,                    *
*    this list of conditions and the following disclaimer in the documentation                    *
*    and/or other materials provided with the distribution.                                       *
*                                                                                                 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND                 *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED                   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                          *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR                 *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                    *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND                     *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT                      *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS                   *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                    *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



#include <stdlib.h>
#include <stdio.h>

#include <blasfeo_target.h>
#include <blasfeo_common.h>
#include <blasfeo_d_aux.h>

#include <hpipm_d_dense_qp_dim.h>
#include <hpipm_d_dense_qp.h>
#include <hpipm_d_dense_qp_sol.h>
#include <hpipm_aux_string.h>
#include <hpipm_aux_mem.h>



#define CREATE_STRVEC blasfeo_create_dvec
#define UNPACK_VEC blasfeo_unpack_dvec
#define PACK_VEC blasfeo_pack_dvec
#define DENSE_QP d_dense_qp
#define DENSE_QP_DIM d_dense_qp_dim
#define DENSE_QP_SOL d_dense_qp_sol
#define REAL double
#define STRVEC blasfeo_dvec
#define SIZE_STRVEC blasfeo_memsize_dvec
#define VECCP_LIBSTR blasfeo_dveccp

#define DENSE_QP_SOL_STRSIZE d_dense_qp_sol_strsize
#define DENSE_QP_SOL_MEMSIZE d_dense_qp_sol_memsize
#define DENSE_QP_SOL_CREATE d_dense_qp_sol_create
#define DENSE_QP_SOL_GET_ALL d_dense_qp_sol_get_all
#define DENSE_QP_SOL_GET d_dense_qp_sol_get
#define DENSE_QP_SOL_GET_V d_dense_qp_sol_get_v
#define DENSE_QP_SOL_GET_SL d_dense_qp_sol_get_sl
#define DENSE_QP_SOL_GET_SU d_dense_qp_sol_get_su
#define DENSE_QP_SOL_GET_PI d_dense_qp_sol_get_pi
#define DENSE_QP_SOL_GET_LAM_LB d_dense_qp_sol_get_lam_lb
#define DENSE_QP_SOL_GET_LAM_UB d_dense_qp_sol_get_lam_ub
#define DENSE_QP_SOL_GET_LAM_LG d_dense_qp_sol_get_lam_lg
#define DENSE_QP_SOL_GET_LAM_UG d_dense_qp_sol_get_lam_ug
#define DENSE_QP_SOL_GET_LAM_LS d_dense_qp_sol_get_lam_ls
#define DENSE_QP_SOL_GET_LAM_US d_dense_qp_sol_get_lam_us
#define DENSE_QP_SOL_GET_VALID_OBJ d_dense_qp_sol_get_valid_obj
#define DENSE_QP_SOL_GET_OBJ d_dense_qp_sol_get_obj
#define DENSE_QP_SOL_SET d_dense_qp_sol_set
#define DENSE_QP_SOL_SET_V d_dense_qp_sol_set_v
#define DENSE_QP_SOL_SET_SL d_dense_qp_sol_set_sl
#define DENSE_QP_SOL_SET_SU d_dense_qp_sol_set_su
#define DENSE_QP_SOL_SET_PI d_dense_qp_sol_set_pi
#define DENSE_QP_SOL_SET_LAM_LB d_dense_qp_sol_set_lam_lb
#define DENSE_QP_SOL_SET_LAM_UB d_dense_qp_sol_set_lam_ub
#define DENSE_QP_SOL_SET_LAM_LG d_dense_qp_sol_set_lam_lg
#define DENSE_QP_SOL_SET_LAM_UG d_dense_qp_sol_set_lam_ug
#define DENSE_QP_SOL_SET_LAM_LS d_dense_qp_sol_set_lam_ls
#define DENSE_QP_SOL_SET_LAM_US d_dense_qp_sol_set_lam_us



#include "x_dense_qp_sol.c"

