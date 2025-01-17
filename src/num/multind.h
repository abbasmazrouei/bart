/* Copyright 2013-2014. The Regents of the University of California.
 * Copyright 2016-2021. Uecker Lab. University Medical Center Göttingen.
 * Copyright 2022. Insitute of Biomedical Imaging. Graz University of Technology.
 * All rights reserved. Use of this source code is governed by
 * a BSD-style license which can be found in the LICENSE file.
 */

#ifndef __MULTIND_H
#define __MULTIND_H	1

#include <string.h>
#include <assert.h>
#ifdef _WIN32
#include <malloc.h>
#else
#include <alloca.h>
#endif

#include <stdbool.h>

#include "misc/cppwrap.h"
#include "misc/nested.h"
#include "misc/types.h"

typedef void CLOSURE_TYPE(md_nary_fun_t)(void* ptr[]);
typedef void CLOSURE_TYPE(md_trafo_fun_t)(long N, long str, void* ptr);
typedef void CLOSURE_TYPE(md_loop_fun_t)(const long* pos);


extern void md_nary(unsigned int C, unsigned int D, const long dim[__VLA(D)], const long* str[__VLA(C)], void* ptr[__VLA(C)], md_nary_fun_t fun);

extern void md_parallel_nary(unsigned int C, unsigned int D, const long dim[__VLA(D)], unsigned long flags, const long* str[__VLA(C)], void* ptr[__VLA(C)], md_nary_fun_t fun);
extern void md_parallel_loop(unsigned int D, const long dim[__VLA(D)], unsigned long flags, md_loop_fun_t fun);

extern void md_loop(unsigned int D, const long dim[__VLA(D)], md_loop_fun_t fun);

extern void md_septrafo2(unsigned int D, const long dimensions[__VLA(D)], unsigned long flags, const long strides[__VLA(D)], void* ptr, md_trafo_fun_t fun);
extern void md_septrafo(unsigned int D, const long dimensions[__VLA(D)], unsigned long flags, void* ptr, size_t size, md_trafo_fun_t fun);


extern void md_clear2(unsigned int D, const long dim[__VLA(D)], const long str[__VLA(D)], void* ptr, size_t size);
extern void md_clear(unsigned int D, const long dim[__VLA(D)], void* ptr, size_t size);
extern void md_swap2(unsigned int D, const long dim[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long istr[__VLA(D)], void* iptr, size_t size);
extern void md_swap(unsigned int D, const long dim[__VLA(D)],  void* optr, void* iptr, size_t size);
extern void md_circular_swap2(unsigned M, unsigned int D, const long dims[__VLA(D)], const long* strs[__VLA(M)], void* ptr[__VLA(M)], size_t size);
extern void md_circular_swap(unsigned M, unsigned int D, const long dims[__VLA(D)], void* ptr[__VLA(M)], size_t size);

extern void md_copy2(unsigned int D, const long dim[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_copy(unsigned int D, const long dim[__VLA(D)],  void* optr, const void* iptr, size_t size);
extern void md_copy_block2(unsigned int D, const long pos[__VLA(D)], const long odim[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long idim[__VLA(D)], const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_copy_block(unsigned int D, const long pos[__VLA(D)], const long odim[__VLA(D)], void* optr, const long idim[__VLA(D)], const void* iptr, size_t size);
extern void md_move_block2(unsigned int D, const long dim[__VLA(D)], const long opos[__VLA(D)], const long odim[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long ipos[__VLA(D)], const long idim[__VLA(D)], const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_move_block(unsigned int D, const long dim[__VLA(D)], const long opos[__VLA(D)], const long odim[__VLA(D)], void* optr, const long ipos[__VLA(D)], const long idim[__VLA(D)], const void* iptr, size_t size);

extern void md_pad(unsigned int D, const void* val, const long odim[__VLA(D)], void* optr, const long idim[__VLA(D)], const void* iptr, size_t size);
extern void md_pad_center(unsigned int D, const void* val, const long odim[__VLA(D)], void* optr, const long idim[__VLA(D)], const void* iptr, size_t size);
extern void md_resize(unsigned int D, const long odim[__VLA(D)], void* optr, const long idim[__VLA(D)], const void* iptr, size_t size);
extern void md_resize_center(unsigned int D, const long odim[__VLA(D)], void* optr, const long idim[__VLA(D)], const void* iptr, size_t size);
extern void md_fill2(unsigned int D, const long dim[__VLA(D)], const long str[__VLA(D)], void* ptr, const void* iptr, size_t size);
extern void md_fill(unsigned int D, const long dim[__VLA(D)], void* ptr, const void* iptr, size_t size);
extern void md_slice2(unsigned int D, unsigned long flags, const long pos[__VLA(D)], const long dim[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_slice(unsigned int D, unsigned long flags, const long pos[__VLA(D)], const long dim[__VLA(D)], void* optr, const void* iptr, size_t size);
extern void md_transpose2(unsigned int D, unsigned int dim1, unsigned int dim2, const long odims[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long idims[__VLA(D)], const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_transpose(unsigned int D, unsigned int dim1, unsigned int dim2, const long odims[__VLA(D)], void* optr, const long idims[__VLA(D)], const void* iptr, size_t size);
extern void md_permute2(unsigned int D, const unsigned int order[__VLA(D)], const long odims[__VLA(D)], const long ostr[__VLA(D)], void* optr, const long idims[__VLA(D)], const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_permute(unsigned int D, const unsigned int order[__VLA(D)], const long odims[__VLA(D)], void* optr, const long idims[__VLA(D)], const void* iptr, size_t size);
extern void md_flip2(unsigned int D, const long dims[__VLA(D)], unsigned long flags, const long ostr[__VLA(D)], void* optr, const long istr[__VLA(D)], const void* iptr, size_t size);
extern void md_flip(unsigned int D, const long dims[__VLA(D)], unsigned long flags, void* optr, const void* iptr, size_t size);

extern void md_swap_flip2(unsigned int D, const long dims[__VLA(D)], unsigned long flags, const long ostr[__VLA(D)], void* optr, const long istr[__VLA(D)], void* iptr, size_t size);
extern void md_swap_flip(unsigned int D, const long dims[__VLA(D)], unsigned long flags, void* optr, void* iptr, size_t size);

extern void md_reshape(unsigned int D, unsigned long flags, const long odims[__VLA(D)], void* optr, const long idims[__VLA(D)], const void* iptr, size_t size);
extern void md_reshape2(unsigned int D, unsigned long flags, const long odims[__VLA(D)], const long ostrs[__VLA(D)], void* optr, const long idims[__VLA(D)], const long istrs[__VLA(D)], const void* iptr, size_t size);

extern void md_copy_diag2(unsigned int D, const long dims[__VLA(D)], unsigned long flags, const long str1[__VLA(D)], void* dst, const long str2[__VLA(D)], const void* src, size_t size);
extern void md_copy_diag(unsigned int D, const long dims[__VLA(D)], unsigned long flags, void* dst, const void* src, size_t size);
extern void md_fill_diag(unsigned int D, const long dims[__VLA(D)], unsigned long flags, void* dst, const void* src, size_t size);

extern void md_circ_shift2(unsigned int D, const long dim[__VLA(D)], const long center[__VLA(D)], const long str1[__VLA(D)], void* dst, const long str2[__VLA(D)], const void* src, size_t size);
extern void md_circ_shift(unsigned int D, const long dim[__VLA(D)], const long center[__VLA(D)], void* dst, const void* src, size_t size);

extern void md_circ_ext2(unsigned int D, const long dims1[__VLA(D)], const long strs1[__VLA(D)], void* dst, const long dims2[__VLA(D)], const long strs2[__VLA(D)], const void* src, size_t size);
extern void md_circ_ext(unsigned int D, const long dims1[__VLA(D)], void* dst, const long dims2[__VLA(D)], const void* src, size_t size);


extern void md_periodic2(unsigned int D, const long dims1[__VLA(D)], const long strs1[__VLA(D)], void* dst, const long dims2[__VLA(D)], const long strs2[__VLA(D)], const void* src, size_t size);
extern void md_periodic(unsigned int D, const long dims1[__VLA(D)], void* dst, const long dims2[__VLA(D)], const void* src, size_t size);

extern _Bool md_compare2(unsigned int D, const long dims[__VLA(D)], const long str1[__VLA(D)], const void* src1,
			const long str2[__VLA(D)], const void* src2, size_t size);
extern _Bool md_compare(unsigned int D, const long dims[__VLA(D)], const void* src1, const void* src2, size_t size);


typedef void* (*md_alloc_fun_t)(unsigned int D, const long dimensions[__VLA(D)], size_t size);

extern void* md_alloc(unsigned int D, const long dimensions[__VLA(D)], size_t size);
extern void* md_calloc(unsigned int D, const long dimensions[__VLA(D)], size_t size);
#ifdef USE_CUDA
extern void* md_alloc_gpu(unsigned int D, const long dimensions[__VLA(D)], size_t size);
extern void* md_gpu_move(unsigned int D, const long dims[__VLA(D)], const void* ptr, size_t size);
#endif
extern void* md_alloc_sameplace(unsigned int D, const long dimensions[__VLA(D)], size_t size, const void* ptr);
extern _Bool md_is_sameplace(const void* ptr1, const void* ptr2);
extern void md_free(const void* p);


extern long md_calc_size(unsigned int D, const long dimensions[__VLA(D)]);
extern long* md_calc_strides(unsigned int D, long str[__VLA(D)], const long dim[__VLA(D)], size_t size);
extern long md_calc_offset(unsigned int D, const long strides[__VLA(D)], const long position[__VLA(D)]);
extern unsigned int md_calc_blockdim(unsigned int D, const long dim[__VLA(D)], const long str[__VLA(D)], size_t size);
extern void md_select_dims(unsigned int D, unsigned long flags, long odims[__VLA(D)], const long idims[__VLA(D)]);
extern void md_copy_dims(unsigned int D, long odims[__VLA(D)], const long idims[__VLA(D)]);
extern void md_copy_strides(unsigned int D, long odims[__VLA(D)], const long idims[__VLA(D)]);
extern void md_merge_dims(unsigned int D, long odims[__VLA(D)], const long dims1[__VLA(D)], const long dims2[__VLA(D)]);
extern _Bool md_check_compat(unsigned int D, unsigned long flags, const long dim1[__VLA(D)], const long dim2[__VLA(D)]);
extern _Bool md_check_bounds(unsigned int D, unsigned long flags, const long dim1[__VLA(D)], const long dim2[__VLA(D)]);
extern void md_singleton_dims(unsigned int D, long dims[__VLA(D)]);
extern void md_singleton_strides(unsigned int D, long strs[__VLA(D)]);
extern void md_set_dims(unsigned int D, long dims[__VLA(D)], long val);
extern void md_min_dims(unsigned int D, unsigned long flags, long odims[__VLA(D)], const long idims1[__VLA(D)], const long idims2[__VLA(D)]);
extern void md_max_dims(unsigned int D, unsigned long flags, long odims[__VLA(D)], const long idims1[__VLA(D)], const long idims2[__VLA(D)]);
extern _Bool md_is_index(unsigned int D, const long pos[__VLA(D)], const long dims[__VLA(D)]);
extern _Bool md_check_dimensions(unsigned int N, const long dims[__VLA(N)], unsigned int flags);
extern _Bool md_check_equal_dims(unsigned int N, const long dims1[__VLA(N)], const long dims2[__VLA(N)], unsigned int flags);
extern void md_permute_dims(unsigned int D, const unsigned int order[__VLA(D)], long odims[__VLA(D)], const long idims[__VLA(D)]);
extern void md_transpose_dims(unsigned int D, unsigned int dim1, unsigned int dim2, long odims[__VLA(D)], const long idims[__VLA(D)]);
extern _Bool md_next(unsigned int D, const long dims[__VLA(D)], unsigned long flags, long pos[__VLA(D)]);

extern unsigned long md_nontriv_dims(unsigned int D, const long dims[__VLA(D)]);
extern unsigned long md_nontriv_strides(unsigned int D, const long dims[__VLA(D)]);


#define MD_INIT_ARRAY(x, y) { [ 0 ... ((x) - 1) ] = (y) }
#define MD_MAKE_ARRAY(T, ...) ((T[]){ __VA_ARGS__ })
#define MD_DIMS(...) MD_MAKE_ARRAY(long, __VA_ARGS__)

#define MD_BIT(x) (1ul << (x))
#define MD_IS_SET(x, y)	((x) & MD_BIT(y))
#define MD_CLEAR(x, y) ((x) & ~MD_BIT(y))
#define MD_SET(x, y)	((x) | MD_BIT(y))

extern int md_max_idx(unsigned long flags);
extern int md_min_idx(unsigned long flags);

#define MD_CAST_ARRAY2_PTR(T, N, dims, x, a, b) \
({						\
	int _a = (a), _b = (b);			\
	const long* _dims = dims;		\
	assert(_a < _b);			\
	assert(!md_check_dimensions((N), _dims, (1 << _a) | (1 << _b))); \
	(T (*)[_dims[_b]][_dims[_a]])(x);	\
})
#define MD_CAST_ARRAY3_PTR(T, N, dims, x, a, b, c) \
({						\
	int _a = (a), _b = (b), _c = (c);	\
	const long* _dims = dims;		\
	assert((_a < _b) && (_b < _c));		\
	assert(!md_check_dimensions((N), _dims, (1 << _a) | (1 << _b | (1 << _c)))); \
	(T (*)[_dims[_c]][_dims[_b]][_dims[_a]])(x); \
})

#define MD_CAST_ARRAY2(T, N, dims, x, a, b) (*MD_CAST_ARRAY2_PTR(T, N, dims, x, a, b))
#define MD_CAST_ARRAY3(T, N, dims, x, a, b, c) (*MD_CAST_ARRAY3_PTR(T, N, dims, x, a, b, c))


#define MD_ACCESS(N, strs, pos, x)	(*({ auto _x = (x); &((_x)[md_calc_offset((N), (strs), (pos)) / sizeof((_x)[0])]); }))

#define MD_STRIDES(N, dims, elsize)	(md_calc_strides(N, alloca(N * sizeof(long)), dims, elsize))

#define MD_SINGLETON_DIMS(N)				\
({							\
	int _N = (N);					\
	long* _dims = alloca(_N * sizeof(long));	\
	md_singleton_dims(_N, _dims);			\
	_dims;						\
})

#define MD_SINGLETON_STRS(N)				\
({							\
	int _N = (N);					\
	long* _dims = alloca(_N * sizeof(long)); 	\
	md_singleton_strides(_N, _dims); 		\
	_dims; 						\
})

#include "misc/cppwrap.h"

#endif // __MULTIND_H

