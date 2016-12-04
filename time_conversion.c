/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge  - Time Conversion
* Date: 04/12/2016
* Licence: For educational purposes only.
*          All rights reserved to the author.
*          For any queries contact me via email geralltf at gmail.com.
* Abstract: N/A
*
*                                      '
*    [ HACKERRANK.COM ]         . ` ;  ::
*                              , : +:;,,@
*                            '#:. '#` + @;
*            ;               :+:,.@#;'.; +,
*            `               '+;.'@'+@@ :@+
*           @              '+;;'+@@'@@' +@'@
*           @              :'::##@+##':@#@@''
*         +:+              #::;;@@,;@@+@##;@@:
*        @'##            ` +;###@#@''#.@@###@@+
*        '#@@            .`@+@#;+@';@@#+@'##@@@++
*       #@@@@            ++@++;;@':+;+:;@+++#@@+#+'
*       #@@@@#          ##@++#++:'+';@#@#:'';+@#;#;@
*      '@@ @@@,        #+#;@#@##;+.,@#@+@+;;''#@#;@+@
*      @#@@@@@#      `;@#@##@+##;#@,#@#@#@;:;;:+@@:@;#,
*      #@@@@@@@#    :'#,:+#'#++@#+#+;@@@@@;''::;'@#+,#'+
*     ,#@@@@@@@@@   ;'+@@;'#@+@#@@@@#+'@@@@;@@##::@;@;,'+
*     @#@@@@@@@@@@  :`+@###+;@';@'+;.`'@@@@@@@#@#@:@,@;:++
*    #@@@@@@@@@@@@@ #@;@#@@+'@'@+#@@@+@@@@@#@'@@#@@;@;@';@'
*    @@@@@    @@@@@@@++++@+'@@@@@@@#@@;+@@@###+@@@@@'#;+;'#@
*   +@@@@@@@@@@@@@@@#+@@@+@+;+@@,+@`@:+@@@###@+` @@@@#';+#;@;
*   @@@@@@@@@@@@@@@@@@;#'##+###@@#+@@@@'@@##@@@@      @';;@'#
*   @#@@@@@@@#@@@@@#@+#@+@#@;@@ FRANKE @@@##@@@#@     ,@:;'@;+
*  #@#@@@@@@@     +@@:#++#+@@@@@#@@@@@@@@@@@@@@@@     ;#@:;'@#+
*  @##@@@@@#       @@@@+#+##'@@@@@++@@#@@@@@@@@@###;   @#@;''#@,
*  @@@@@@@@        '@##'#@;#@@@@@@@@@@@@@@@   @@@@#+`  @@'@;'';@'
* ,@@ @@@,         @#+#@''',#@@@@@@@@@@@@@@@@@@@@@#@#' `@@'@'+''@++;
* @##@@@@          .@##+#+#;@@@@@@@@#@@@@@@#@@@#@@@@+@. @  ;''++'#'++
* @@@@@#           `#@#'+++`,+@@@@@#@@  +. #@@#  @@@##@ @   ;''.`'#+#+
* @@@@'             #@+@+:+`` @@@#@+`      @@@+    @@#++    ,@'+ @'++#
*'@@@@              #@##@#+# #@@@@         @@@'     @@@@'    '@++ '+##+
*@@@                @@@;@#'+,#@@+          @@@.      #@@@     '+'#+;++@'
*@@;                '@#@##'#'@ @           @@@        @@+      '''@'+++#:
*@@;                 ###@@@,#.             +#@        .@#,     ,''#''+++'
*@@                  `'@@'#@#.   ,         ###`        @++      ##' .;++#
*@@                +  :@@#+@,@+  ,     '   @@#+        ;#@:      '+   ++##
*@                  '  ++@.''::; '@   ;    ##@@:        #@:       +;   '++
*@                  `;   @;@#+' #@;  :     @##@+        @#'     +  +    '+
*                    +'; :@'':: +'  #+     +##@@:       @:+        +     +'
*                     @''#';@+++: ,.@      #@@@@+       ##'         .    :#
*                      `@+ `';;+@' ;,       @#@@#@       '+               +
*                       @@@ ',,+# @`        @@#@@#       @;               ,:
*                         #;+.'':,          @@#,@@;      @+                #
*                         :@#+.''`           @# @@@      @#                .
*                         '@#''#;             @ @@#      @+                 `
*                          @#@@#;             @:`@#      @#
*                           @@@+              @: @#      #+
*                            ''               @; '#      '+
*                            ,,               @. ,@      .++
*                            `                @`  @      .@
*                                             +   @       @
*                                                 .        '
**********************************************************  +  */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

typedef struct tm* TimeInfo;
typedef char* String;

void str_lower(String p) 
{
	for (; *p; ++p) *p = *p >= 'A'&&*p <= 'Z' ? *p | 0x60 : *p;
}

TimeInfo parse_time24(String s) 
{
	TimeInfo info = (TimeInfo)malloc(sizeof(TimeInfo));
	char* amPm = (char*)malloc(sizeof(char) * 3);

	sscanf(s, "%d:%d:%d%s", &info->tm_hour, &info->tm_min, &info->tm_sec, amPm);
	str_lower(amPm);

	// Parse as 24 hour time
	if (strcmp(amPm, "pm") == 0) 
	{
		if (info->tm_hour < 12) 
		{
			info->tm_hour += 12;
		}
		else if (info->tm_hour > 12) 
		{
			info->tm_hour -= 12;
		}
	}
	if (strcmp(amPm, "am") == 0) 
	{
		if (info->tm_hour >= 12) 
		{
			info->tm_hour -= 12;
		}
	}

	info->tm_mday = 1;
	info->tm_isdst = 0;
	info->tm_mon = 0;
	info->tm_wday = 0;
	info->tm_yday = 0;
	info->tm_year = 1900;

	return info;
}

String stringify_time24(TimeInfo t)
{
	String buffer = (String)malloc(10240 * sizeof(char));
	
	sprintf(buffer, "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);

	return buffer;
}

int main() 
{
	String t24;
	String t12;

	//t12 = "07:59:45PM"; /*
	t12 = (char *)malloc(10240 * sizeof(char));
	scanf("%s", t12); // */
	
	//t12 = "12:00:00PM";
	//t12 = "12:00:00AM";

	TimeInfo info = parse_time24(t12);
	
	t24 = stringify_time24(info);

	printf("%s", t24);

	return 0;
}