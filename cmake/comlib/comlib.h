/**
 * @file			comlib.h
 * @author		au
 * @email			ghaucience@gmail.h
 * @version		V1.0.0
 * @date			2017-11-20
 * @licence		GNU General Public License (GPL)
 * @brief			common library
 * @detail		detail
 * attention	
 *	this file is a test common library \n
 *
 *  this file is a test common library \n
 *  this file is a test common library \n
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|-------
 * V1.0.0 |au    |2017-11-20|Create File
 * <h2><center>&copy;COPYRIGHT 2021 Aux ALL Rights Reserved. </center></h2>
 */


typedef struct stMyDef {
	int a; /**< member a */
	int b; /**< member b */
} stMyDef_t;

typedef enum {
	MyZero = 0, /**< ZERO */
	MyOne  = 1, /**< ONE */
} emMyEnum_t;

/**
 * @breif mysqrt
 *
 * @param[in] x : input arguments
 * @note must input
 *
 * @return 
 *			0 succcess \n
 *			1 fail\n
 *
 * @par Sample
 * @code
 *	doulbe a;
 *	doulbe b = mysqrt(a);
 * @endcode
 */
double mysqrt(double x);
