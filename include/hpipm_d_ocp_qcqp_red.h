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

#ifndef HPIPM_D_OCP_QCQP_RED_H_
#define HPIPM_D_OCP_QCQP_RED_H_



#include <blasfeo_target.h>
#include <blasfeo_common.h>

#include <hpipm_d_ocp_qcqp_dim.h>
#include <hpipm_d_ocp_qp.h>
#include <hpipm_d_ocp_qcqp_sol.h>



#ifdef __cplusplus
extern "C" {
#endif



struct d_ocp_qcqp_reduce_eq_dof_arg
	{
	double lam_min;
	double t_min;
	int alias_unchanged; // do not keep copy unchanged stage
	int comp_prim_sol; // primal solution (v)
	int comp_dual_sol_eq; // dual solution equality constr (pi)
	int comp_dual_sol_ineq; // dual solution inequality constr (lam t)
	hpipm_size_t memsize; // memory size in bytes
	};



struct d_ocp_qcqp_reduce_eq_dof_ws
	{
	struct blasfeo_dvec *tmp_nuxM;
	struct blasfeo_dvec *tmp_nbgqM;
	int *e_imask_ux;
	int *e_imask_d;
	hpipm_size_t memsize; // memory size in bytes
	};



//
void d_ocp_qcqp_dim_reduce_eq_dof(struct d_ocp_qcqp_dim *dim, struct d_ocp_qcqp_dim *dim_red);
//
hpipm_size_t d_ocp_qcqp_reduce_eq_dof_arg_memsize();
//
void d_ocp_qcqp_reduce_eq_dof_arg_create(struct d_ocp_qcqp_reduce_eq_dof_arg *arg, void *mem);
//
void d_ocp_qcqp_reduce_eq_dof_arg_set_default(struct d_ocp_qcqp_reduce_eq_dof_arg *arg);
//
void d_ocp_qcqp_reduce_eq_dof_arg_set_alias_unchanged(int *value, struct d_ocp_qcqp_reduce_eq_dof_arg *arg);
//
void d_ocp_qcqp_reduce_eq_dof_arg_set_comp_prim_sol(int *value, struct d_ocp_qcqp_reduce_eq_dof_arg *arg);
//
void d_ocp_qcqp_reduce_eq_dof_arg_set_comp_dual_sol_eq(int *value, struct d_ocp_qcqp_reduce_eq_dof_arg *arg);
//
void d_ocp_qcqp_reduce_eq_dof_arg_set_comp_dual_sol_ineq(int *value, struct d_ocp_qcqp_reduce_eq_dof_arg *arg);
//
hpipm_size_t d_ocp_qcqp_reduce_eq_dof_ws_memsize(struct d_ocp_qcqp_dim *dim);
//
void d_ocp_qcqp_reduce_eq_dof_ws_create(struct d_ocp_qcqp_dim *dim, struct d_ocp_qcqp_reduce_eq_dof_ws *work, void *mem);
//
void d_ocp_qcqp_reduce_eq_dof(struct d_ocp_qcqp *qp, struct d_ocp_qcqp *qp_red, struct d_ocp_qcqp_reduce_eq_dof_arg *arg, struct d_ocp_qcqp_reduce_eq_dof_ws *work);
//
void d_ocp_qcqp_reduce_eq_dof_lhs(struct d_ocp_qcqp *qp, struct d_ocp_qcqp *qp_red, struct d_ocp_qcqp_reduce_eq_dof_arg *arg, struct d_ocp_qcqp_reduce_eq_dof_ws *work);
//
void d_ocp_qcqp_reduce_eq_dof_rhs(struct d_ocp_qcqp *qp, struct d_ocp_qcqp *qp_red, struct d_ocp_qcqp_reduce_eq_dof_arg *arg, struct d_ocp_qcqp_reduce_eq_dof_ws *work);
//
void d_ocp_qcqp_restore_eq_dof(struct d_ocp_qcqp *qp, struct d_ocp_qcqp_sol *qp_sol_red, struct d_ocp_qcqp_sol *qp_sol, struct d_ocp_qcqp_reduce_eq_dof_arg *arg, struct d_ocp_qcqp_reduce_eq_dof_ws *work);
//
void d_ocp_qcqp_reduce_eq_dof_sol(struct d_ocp_qcqp *qp, struct d_ocp_qcqp_sol *qp_sol, struct d_ocp_qcqp_sol *qp_sol_red, struct d_ocp_qcqp_reduce_eq_dof_arg *arg, struct d_ocp_qcqp_reduce_eq_dof_ws *work);



#ifdef __cplusplus
}	// #extern "C"
#endif



#endif // HPIPM_D_OCP_QCQP_RED_H_

