/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptableDateFormat.idl
 */

#ifndef __gen_nsIScriptableDateFormat_h__
#define __gen_nsIScriptableDateFormat_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int32_t  nsDateFormatSelector;

enum
{
    kDateFormatNone = 0,            // do not include the date  in the format string
    kDateFormatLong,                // provides the long date format for the given locale
    kDateFormatShort,               // provides the short date format for the given locale
    kDateFormatYearMonth,           // formats using only the year and month 
    kDateFormatWeekday              // week day (e.g. Mon, Tue)
};
typedef int32_t  nsTimeFormatSelector;

enum
{
    kTimeFormatNone = 0,            // don't include the time in the format string
    kTimeFormatSeconds,             // provides the time format with seconds in the  given locale 
    kTimeFormatNoSeconds,           // provides the time format without seconds in the given locale 
    kTimeFormatSecondsForce24Hour,  // forces the time format to use the 24 clock, regardless of the locale conventions
    kTimeFormatNoSecondsForce24Hour // forces the time format to use the 24 clock, regardless of the locale conventions
};
// Define Contractid and CID
// {2EA2E7D0-4095-11d3-9144-006008A6EDF6}
#define NS_SCRIPTABLEDATEFORMAT_CID \
{ 0x2ea2e7d0, 0x4095, 0x11d3, { 0x91, 0x44, 0x0, 0x60, 0x8, 0xa6, 0xed, 0xf6 } }
#define NS_SCRIPTABLEDATEFORMAT_CONTRACTID "@mozilla.org/intl/scriptabledateformat;1"
extern nsresult
NS_NewScriptableDateFormat(nsISupports* aOuter, REFNSIID aIID, void** aResult);

/* starting interface:    nsIScriptableDateFormat */
#define NS_ISCRIPTABLEDATEFORMAT_IID_STR "0c89efb0-1aae-11d3-9141-006008a6edf6"

#define NS_ISCRIPTABLEDATEFORMAT_IID \
  {0x0c89efb0, 0x1aae, 0x11d3, \
    { 0x91, 0x41, 0x00, 0x60, 0x08, 0xa6, 0xed, 0xf6 }}

class NS_NO_VTABLE nsIScriptableDateFormat : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEDATEFORMAT_IID)

  enum {
    dateFormatNone = 0,
    dateFormatLong = 1,
    dateFormatShort = 2,
    dateFormatYearMonth = 3,
    dateFormatWeekday = 4,
    timeFormatNone = 0,
    timeFormatSeconds = 1,
    timeFormatNoSeconds = 2,
    timeFormatSecondsForce24Hour = 3,
    timeFormatNoSecondsForce24Hour = 4
  };

  /* wstring FormatDateTime (in wstring locale, in long dateFormatSelector, in long timeFormatSelector, in long year, in long month, in long day, in long hour, in long minute, in long second); */
  NS_IMETHOD FormatDateTime(const char16_t * locale, int32_t dateFormatSelector, int32_t timeFormatSelector, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) = 0;

  /* wstring FormatDate (in wstring locale, in long dateFormatSelector, in long year, in long month, in long day); */
  NS_IMETHOD FormatDate(const char16_t * locale, int32_t dateFormatSelector, int32_t year, int32_t month, int32_t day, char16_t * *_retval) = 0;

  /* wstring FormatTime (in wstring locale, in long timeFormatSelector, in long hour, in long minute, in long second); */
  NS_IMETHOD FormatTime(const char16_t * locale, int32_t timeFormatSelector, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableDateFormat, NS_ISCRIPTABLEDATEFORMAT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEDATEFORMAT \
  NS_IMETHOD FormatDateTime(const char16_t * locale, int32_t dateFormatSelector, int32_t timeFormatSelector, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval); \
  NS_IMETHOD FormatDate(const char16_t * locale, int32_t dateFormatSelector, int32_t year, int32_t month, int32_t day, char16_t * *_retval); \
  NS_IMETHOD FormatTime(const char16_t * locale, int32_t timeFormatSelector, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEDATEFORMAT(_to) \
  NS_IMETHOD FormatDateTime(const char16_t * locale, int32_t dateFormatSelector, int32_t timeFormatSelector, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) { return _to FormatDateTime(locale, dateFormatSelector, timeFormatSelector, year, month, day, hour, minute, second, _retval); } \
  NS_IMETHOD FormatDate(const char16_t * locale, int32_t dateFormatSelector, int32_t year, int32_t month, int32_t day, char16_t * *_retval) { return _to FormatDate(locale, dateFormatSelector, year, month, day, _retval); } \
  NS_IMETHOD FormatTime(const char16_t * locale, int32_t timeFormatSelector, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) { return _to FormatTime(locale, timeFormatSelector, hour, minute, second, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEDATEFORMAT(_to) \
  NS_IMETHOD FormatDateTime(const char16_t * locale, int32_t dateFormatSelector, int32_t timeFormatSelector, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatDateTime(locale, dateFormatSelector, timeFormatSelector, year, month, day, hour, minute, second, _retval); } \
  NS_IMETHOD FormatDate(const char16_t * locale, int32_t dateFormatSelector, int32_t year, int32_t month, int32_t day, char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatDate(locale, dateFormatSelector, year, month, day, _retval); } \
  NS_IMETHOD FormatTime(const char16_t * locale, int32_t timeFormatSelector, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatTime(locale, timeFormatSelector, hour, minute, second, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableDateFormat : public nsIScriptableDateFormat
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEDATEFORMAT

  nsScriptableDateFormat();

private:
  ~nsScriptableDateFormat();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableDateFormat, nsIScriptableDateFormat)

nsScriptableDateFormat::nsScriptableDateFormat()
{
  /* member initializers and constructor code */
}

nsScriptableDateFormat::~nsScriptableDateFormat()
{
  /* destructor code */
}

/* wstring FormatDateTime (in wstring locale, in long dateFormatSelector, in long timeFormatSelector, in long year, in long month, in long day, in long hour, in long minute, in long second); */
NS_IMETHODIMP nsScriptableDateFormat::FormatDateTime(const char16_t * locale, int32_t dateFormatSelector, int32_t timeFormatSelector, int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring FormatDate (in wstring locale, in long dateFormatSelector, in long year, in long month, in long day); */
NS_IMETHODIMP nsScriptableDateFormat::FormatDate(const char16_t * locale, int32_t dateFormatSelector, int32_t year, int32_t month, int32_t day, char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring FormatTime (in wstring locale, in long timeFormatSelector, in long hour, in long minute, in long second); */
NS_IMETHODIMP nsScriptableDateFormat::FormatTime(const char16_t * locale, int32_t timeFormatSelector, int32_t hour, int32_t minute, int32_t second, char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableDateFormat_h__ */