
#include "FLAME.h"

fla_caqr2ut_t*   flash_caqr2ut_cntl_leaf;
fla_caqr2ut_t*   flash_caqr2ut_cntl;
fla_blocksize_t* flash_caqr2ut_var2_bsize;

void FLASH_CAQR2_UT_cntl_init()
{
	// Set blocksize for hierarchical storage.
	flash_caqr2ut_var2_bsize = FLA_Blocksize_create( 1, 1, 1, 1 );

	// Create a control tree to invoke variant 1.
	flash_caqr2ut_cntl_leaf = FLA_Cntl_caqr2ut_obj_create( FLA_HIER,
	                                                       FLA_SUBPROBLEM, 
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL,
	                                                       NULL );

	// Create a control tree to invoke variant 2.
	flash_caqr2ut_cntl    = FLA_Cntl_caqr2ut_obj_create( FLA_HIER,
	                                                     FLA_BLOCKED_VARIANT2, 
	                                                     flash_caqr2ut_var2_bsize,
	                                                     flash_caqr2ut_cntl_leaf,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL );
}

void FLASH_CAQR2_UT_cntl_finalize()
{
	FLA_Cntl_obj_free( flash_caqr2ut_cntl_leaf );
	FLA_Cntl_obj_free( flash_caqr2ut_cntl );

	FLA_Blocksize_free( flash_caqr2ut_var2_bsize );
}
