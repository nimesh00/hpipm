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

#ifndef HPIPM_S_OCP_QP_SOL_H_
#define HPIPM_S_OCP_QP_SOL_H_



#include <blasfeo_target.h>
#include <blasfeo_common.h>

#include "hpipm_s_ocp_qp_dim.h"



#ifdef __cplusplus
extern "C" {
#endif



struct s_ocp_qp_sol
	{
	struct s_ocp_qp_dim *dim;
	struct blasfeo_svec *ux;
	struct blasfeo_svec *pi;
	struct blasfeo_svec *lam;
	struct blasfeo_svec *t;
	void *misc;
	hpipm_size_t memsize; // memory size in bytes
	};



//
hpipm_size_t s_ocp_qp_sol_strsize();
//
hpipm_size_t s_ocp_qp_sol_memsize(struct s_ocp_qp_dim *dim);
//
void s_ocp_qp_sol_create(struct s_ocp_qp_dim *dim, struct s_ocp_qp_sol *qp_sol, void *memory);
//
void s_ocp_qp_sol_copy_all(struct s_ocp_qp_sol *qp_sol_orig, struct s_ocp_qp_sol *qp_sol_dest);
//
void s_qp_sol_get_all(struct s_ocp_qp_sol *qp_sol, float **u, float **x, float **ls, float **us, float **pi, float **lam_lb, float **lam_ub, float **lam_lg, float **lam_ug, float **lam_ls, float **lam_us);
//
void s_qp_sol_get_all_rowmaj(struct s_ocp_qp_sol *qp_sol, float **u, float **x, float **ls, float **us, float **pi, float **lam_lb, float **lam_ub, float **lam_lg, float **lam_ug, float **lam_ls, float **lam_us);
//
void s_ocp_qp_sol_set_all(float **u, float **x, float **ls, float **us, float **pi, float **lam_lb, float **lam_ub, float **lam_lg, float **lam_ug, float **lam_ls, float **lam_us, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_zero(struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_get(char *field, int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_u(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_x(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_sl(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_su(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_pi(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_lb(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_lbu(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_lbx(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_ub(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_ubu(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_ubx(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_lg(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_ug(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_ls(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_get_lam_us(int stage, struct s_ocp_qp_sol *qp_sol, float *vec);
//
void s_ocp_qp_sol_set(char *field, int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_u(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_x(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_sl(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_su(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_pi(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_lb(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_lbu(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_lbx(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_ub(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_ubu(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_ubx(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_lg(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_ug(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_ls(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);
//
void s_ocp_qp_sol_set_lam_us(int stage, float *vec, struct s_ocp_qp_sol *qp_sol);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif // HPIPM_S_OCP_QP_SOL_H_
