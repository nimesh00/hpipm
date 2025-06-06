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



#ifndef HPIPM_S_DENSE_QP_SOL_H_
#define HPIPM_S_DENSE_QP_SOL_H_



#include <blasfeo_target.h>
#include <blasfeo_common.h>

#include "hpipm_s_dense_qp_dim.h"



#ifdef __cplusplus
extern "C" {
#endif



struct s_dense_qp_sol
	{
	struct s_dense_qp_dim *dim;
	struct blasfeo_svec *v;
	struct blasfeo_svec *pi;
	struct blasfeo_svec *lam;
	struct blasfeo_svec *t;
	void *misc;
	float obj;
	int valid_obj;
	hpipm_size_t memsize;
	};



//
hpipm_size_t s_dense_qp_sol_strsize();
//
hpipm_size_t s_dense_qp_sol_memsize(struct s_dense_qp_dim *dim);
//
void s_dense_qp_sol_create(struct s_dense_qp_dim *dim, struct s_dense_qp_sol *qp_sol, void *memory);
//
void s_dense_qp_sol_get_all(struct s_dense_qp_sol *qp_sol, float *v, float *ls, float *us, float *pi, float *lam_lb, float *lam_ub, float *lam_lg, float *lam_ug, float *lam_ls, float *lam_us);
//
void s_dense_qp_sol_get(char *field, struct s_dense_qp_sol *sol, void *value);
//
void s_dense_qp_sol_get_v(struct s_dense_qp_sol *sol, float *v);
//
void s_dense_qp_sol_get_sl(struct s_dense_qp_sol *sol, float *sl);
//
void s_dense_qp_sol_get_su(struct s_dense_qp_sol *sol, float *su);
//
void s_dense_qp_sol_get_pi(struct s_dense_qp_sol *sol, float *pi);
//
void s_dense_qp_sol_get_lam_lb(struct s_dense_qp_sol *sol, float *lam_lb);
//
void s_dense_qp_sol_get_lam_ub(struct s_dense_qp_sol *sol, float *lam_ub);
//
void s_dense_qp_sol_get_lam_lg(struct s_dense_qp_sol *sol, float *lam_lg);
//
void s_dense_qp_sol_get_lam_ug(struct s_dense_qp_sol *sol, float *lam_ug);
//
void s_dense_qp_sol_get_lam_ls(struct s_dense_qp_sol *sol, float *lam_ls);
//
void s_dense_qp_sol_get_lam_us(struct s_dense_qp_sol *sol, float *lam_us);
//
void s_dense_qp_sol_get_valid_obj(struct s_dense_qp_sol *sol, int *valid_obj);
//
void s_dense_qp_sol_get_obj(struct s_dense_qp_sol *sol, float *obj);
//
void s_dense_qp_sol_set(char *field, void *value, struct s_dense_qp_sol *qp_sol);
//
void s_dense_qp_sol_set_v(float *v, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_sl(float *sl, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_su(float *su, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_pi(float *pi, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_lb(float *lam_lb, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_ub(float *lam_ub, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_lg(float *lam_lg, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_ug(float *lam_ug, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_ls(float *lam_ls, struct s_dense_qp_sol *sol);
//
void s_dense_qp_sol_set_lam_us(float *lam_us, struct s_dense_qp_sol *sol);


#ifdef __cplusplus
} /* extern "C" */
#endif



#endif // HPIPM_S_DENSE_QP_SOL_H_
