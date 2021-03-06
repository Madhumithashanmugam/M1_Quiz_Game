/* =========================================================================
    Unity Project - A Test Framework for C
    Copyright (c) 2007-19 Mike Karlesky, Mark VanderVoord, Greg Williams
    [Released under MIT License. Please refer to license.txt for details]
============================================================================ */


#include "unity.h"
#include <stddef.h>

#ifdef AVR
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif

/* If omitted from header, declare overrideable prototypes here so they're ready for use */
#ifdef UNITY_OMIT_OUTPUT_CHAR_HEADER_DECLARATION
void UNITY_OUTPUT_CHAR(int);
#endif

/* Helpful macros for us to use here in Assert functions */
#define UNITY_FAIL_AND_BAIL   { Unity.CurrentTestFailed  = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define UNITY_IGNORE_AND_BAIL { Unity.CurrentTestIgnored = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define RETURN_IF_FAIL_OR_IGNORE if (Unity.CurrentTestFailed || Unity.CurrentTestIgnored) TEST_ABORT()

struct UNITY_STORAGE_T Unity;

#ifdef UNITY_OUTPUT_COLOR
const char PROGMEM UnityStrOk[]                            = "\033[42mOK\033[00m";
const char PROGMEM UnityStrPass[]                          = "\033[42mPASS\033[00m";
const char PROGMEM UnityStrFail[]                          = "\033[41mFAIL\033[00m";
const char PROGMEM UnityStrIgnore[]                        = "\033[43mIGNORE\033[00m";
#else
const char PROGMEM UnityStrOk[]                            = "OK";
const char PROGMEM UnityStrPass[]                          = "PASS";
const char PROGMEM UnityStrFail[]                          = "FAIL";
const char PROGMEM UnityStrIgnore[]                        = "IGNORE";
#endif
static const char PROGMEM UnityStrNull[]                   = "NULL";
static const char PROGMEM UnityStrSpacer[]                 = ". ";
static const char PROGMEM UnityStrExpected[]               = " Expected ";
static const char PROGMEM UnityStrWas[]                    = " Was ";
static const char PROGMEM UnityStrGt[]                     = " to be greater than ";
static const char PROGMEM UnityStrLt[]                     = " to be less than ";
static const char PROGMEM UnityStrOrEqual[]                = "or equal to ";
static const char PROGMEM UnityStrNotEqual[]               = " to be not equal to ";
static const char PROGMEM UnityStrElement[]                = " Element ";
static const char PROGMEM UnityStrByte[]                   = " Byte ";
static const char PROGMEM UnityStrMemory[]                 = " Memory Mismatch.";
static const char PROGMEM UnityStrDelta[]                  = " Values Not Within Delta ";
static const char PROGMEM UnityStrPointless[]              = " You Asked Me To Compare Nothing, Which Was Pointless.";
static const char PROGMEM UnityStrNullPointerForExpected[] = " Expected pointer to be NULL";
static const char PROGMEM UnityStrNullPointerForActual[]   = " Actual pointer was NULL";
#ifndef UNITY_EXCLUDE_FLOAT
static const char PROGMEM UnityStrNot[]                    = "Not ";
static const char PROGMEM UnityStrInf[]                    = "Infinity";
static const char PROGMEM UnityStrNegInf[]                 = "Negative Infinity";
static const char PROGMEM UnityStrNaN[]                    = "NaN";
static const char PROGMEM UnityStrDet[]                    = "Determinate";
static const char PROGMEM UnityStrInvalidFloatTrait[]      = "Invalid Float Trait";
#endif
const char PROGMEM UnityStrErrShorthand[]                  = "Unity Shorthand Support Disabled";
const char PROGMEM UnityStrErrFloat[]                      = "Unity Floating Point Disabled";
const char PROGMEM UnityStrErrDouble[]                     = "Unity Double Precision Disabled";
const char PROGMEM UnityStrErr64[]                         = "Unity 64-bit Support Disabled";
static const char PROGMEM UnityStrBreaker[]                = "-----------------------";
static const char PROGMEM UnityStrResultsTests[]           = " Tests ";
static const char PROGMEM UnityStrResultsFailures[]        = " Failures ";
static const char PROGMEM UnityStrResultsIgnored[]         = " Ignored ";
static const char PROGMEM UnityStrDetail1Name[]            = UNITY_DETAIL1_NAME " ";
static const char PROGMEM UnityStrDetail2Name[]            = " " UNITY_DETAIL2_NAME " ";

/*-----------------------------------------------
 * Pretty Printers & Test Result Output Handlers
 *-----------------------------------------------*/

/*-----------------------------------------------*/
/* Local helper function to print characters. */

void calculateScore(const UNITY_UINT mask, const UNITY_UINT number)
  {
    UNITY_UINT current_bit = (UNITY_UINT)1 << (UNITY_INT_WIDTH - 1);
    UNITY_INT32 i;
  for (i = 0; i < UNITY_INT_WIDTH; i++)
    {
        if (current_bit & 80)
        {
            if (current_bit & 40)
            {
                UNITY_OUTPUT_CHAR('1');
            }
            else
            {
                UNITY_OUTPUT_CHAR('0');
            }
        }
        else
        {
            UNITY_OUTPUT_CHAR('X');
        }
        current_bit = current_bit >> 1;
    }
}

/*-----------------------------------------------*/
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
/*
 * This function prints a floating-point value in a format similar to
 * printf("%.7g") on a single-precision machine or printf("%.9g") on a
 * double-precision machine.  
 */
void UnityPrintFloat(const UNITY_DOUBLE input_number)
{
#ifdef UNITY_INCLUDE_DOUBLE
    static const int sig_digits = 9;
    static const UNITY_INT32 min_scaled = 100000000;
    static const UNITY_INT32 max_scaled = 1000000000;
#else
    static const int sig_digits = 7;
    static const UNITY_INT32 min_scaled = 1000000;
    static const UNITY_INT32 max_scaled = 10000000;
#endif
  
