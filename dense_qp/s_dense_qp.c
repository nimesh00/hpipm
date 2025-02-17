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
#include <blasfeo_s_aux.h>

#include <hpipm_s_dense_qp_dim.h>
#include <hpipm_s_dense_qp.h>
#include <hpipm_aux_string.h>
#include <hpipm_aux_mem.h>



#define SINGLE_PRECISION



#define CREATE_STRMAT blasfeo_create_smat
#define CREATE_STRVEC blasfeo_create_svec
#define CVT_MAT2STRMAT blasfeo_pack_smat
#define CVT_TRAN_MAT2STRMAT blasfeo_pack_tran_smat
#define CVT_TRAN_STRMAT2MAT blasfeo_unpack_tran_smat
#define PACK_VEC blasfeo_pack_svec
#define CVT_STRMAT2MAT blasfeo_unpack_smat
#define UNPACK_VEC blasfeo_unpack_svec
#define DENSE_QP s_dense_qp
#define DENSE_QP_DIM s_dense_qp_dim
#define GECP blasfeo_sgecp
#define GESE blasfeo_sgese
#define REAL float
#define ROWIN_LIBSTR blasfeo_srowin
#define SIZE_STRMAT blasfeo_memsize_smat
#define SIZE_STRVEC blasfeo_memsize_svec
#define STRMAT blasfeo_smat
#define STRVEC blasfeo_svec
#define VECCP blasfeo_sveccp
#define VECSC blasfeo_svecsc
#define VECSE blasfeo_svecse

#define DENSE_QP_MEMSIZE s_dense_qp_memsize
#define DENSE_QP_CREATE s_dense_qp_create
#define DENSE_QP_COPY_ALL s_dense_qp_copy_all
#define DENSE_QP_SET_ALL_ZERO s_dense_qp_set_all_zero
#define DENSE_QP_SET_RHS_ZERO s_dense_qp_set_rhs_zero
#define DENSE_QP_SET_ALL s_dense_qp_set_all
#define DENSE_QP_GET_ALL s_dense_qp_get_all
#define DENSE_QP_SET s_dense_qp_set
#define DENSE_QP_SET_H s_dense_qp_set_H
#define DENSE_QP_SET_G s_dense_qp_set_g
#define DENSE_QP_SET_A s_dense_qp_set_A
#define DENSE_QP_SET_B s_dense_qp_set_b
#define DENSE_QP_SET_IDXB s_dense_qp_set_idxb
#define DENSE_QP_SET_JB s_dense_qp_set_Jb
#define DENSE_QP_SET_LB s_dense_qp_set_lb
#define DENSE_QP_SET_LB_MASK s_dense_qp_set_lb_mask
#define DENSE_QP_SET_UB s_dense_qp_set_ub
#define DENSE_QP_SET_UB_MASK s_dense_qp_set_ub_mask
#define DENSE_QP_SET_C s_dense_qp_set_C
#define DENSE_QP_SET_LG s_dense_qp_set_lg
#define DENSE_QP_SET_LG_MASK s_dense_qp_set_lg_mask
#define DENSE_QP_SET_UG s_dense_qp_set_ug
#define DENSE_QP_SET_UG_MASK s_dense_qp_set_ug_mask
#define DENSE_QP_SET_HQ s_dense_qp_set_Hq
#define DENSE_QP_SET_GQ s_dense_qp_set_gq
#define DENSE_QP_SET_UQ s_dense_qp_set_uq
#define DENSE_QP_SET_IDXS s_dense_qp_set_idxs
#define DENSE_QP_SET_IDXS_REV s_dense_qp_set_idxs_rev
#define DENSE_QP_SET_JSB s_dense_qp_set_Jsb
#define DENSE_QP_SET_JSG s_dense_qp_set_Jsg
#define DENSE_QP_SET_ZZL s_dense_qp_set_Zl
#define DENSE_QP_SET_ZZU s_dense_qp_set_Zu
#define DENSE_QP_SET_ZL s_dense_qp_set_zl
#define DENSE_QP_SET_ZU s_dense_qp_set_zu
#define DENSE_QP_SET_LLS s_dense_qp_set_lls
#define DENSE_QP_SET_LLS_MASK s_dense_qp_set_lls_mask
#define DENSE_QP_SET_LUS s_dense_qp_set_lus
#define DENSE_QP_SET_LUS_MASK s_dense_qp_set_lus_mask
#define DENSE_QP_GET_H s_dense_qp_get_H
#define DENSE_QP_GET_G s_dense_qp_get_g
#define DENSE_QP_GET_A s_dense_qp_get_A
#define DENSE_QP_GET_B s_dense_qp_get_b
#define DENSE_QP_GET_IDXB s_dense_qp_get_idxb
#define DENSE_QP_GET_LB s_dense_qp_get_lb
#define DENSE_QP_GET_LB_MASK s_dense_qp_get_lb_mask
#define DENSE_QP_GET_UB s_dense_qp_get_ub
#define DENSE_QP_GET_UB_MASK s_dense_qp_get_ub_mask
#define DENSE_QP_GET_C s_dense_qp_get_C
#define DENSE_QP_GET_LG s_dense_qp_get_lg
#define DENSE_QP_GET_LG_MASK s_dense_qp_get_lg_mask
#define DENSE_QP_GET_UG s_dense_qp_get_ug
#define DENSE_QP_GET_UG_MASK s_dense_qp_get_ug_mask
#define DENSE_QP_GET_IDXS s_dense_qp_get_idxs
#define DENSE_QP_GET_IDXS_REV s_dense_qp_get_idxs_rev
#define DENSE_QP_GET_ZZL s_dense_qp_get_Zl
#define DENSE_QP_GET_ZZU s_dense_qp_get_Zu
#define DENSE_QP_GET_ZL s_dense_qp_get_zl
#define DENSE_QP_GET_ZU s_dense_qp_get_zu
#define DENSE_QP_GET_LS s_dense_qp_get_ls
#define DENSE_QP_GET_LS_MASK s_dense_qp_get_ls_mask
#define DENSE_QP_GET_US s_dense_qp_get_us
#define DENSE_QP_GET_US_MASK s_dense_qp_get_us_mask
#define DENSE_QP_SET_ALL_ROWMAJ s_dense_qp_set_all_rowmaj
#define DENSE_QP_GET_ALL_ROWMAJ s_dense_qp_get_all_rowmaj

#include "x_dense_qp.c"

