/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge - Compare two linked lists 
* Date: 19/12/2016
* Licence: For educational purposes only..
*          All rights reserved to the author..
*          For any queries contact me via email geralltf attt gmail doott com.
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

/*
Compare two linked lists A and B
Return 1 if they are identical and 0 if they are not.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
return back the pointer to the head of the linked list in the below method.
*/


/* No. Using just what is specified above turned out to be problematic for the compiler.
The 'struct Node' definition is different to the requirement of a type defined 'Node' definition. 
See below for an additional typedef  */

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node; // the fix to get this to compile in your own dev environment 

#include <stdio.h>
#include <stdlib.h>

Node* InsertNth(Node *head, int data, int position)
{
	Node *n, *c;
	int index = 0;

	if (position == 0)
	{
		/* Create a node */
		n = (Node*)malloc(sizeof(Node));
		n->data = data;

		// insert as new first item in list
		n->next = head;
		return n;
	}
	else
	{
		c = head; // start at top of list

		// enumerate through list until the node just before the end position has been reached 

		while (++index < position) 
		{
			c = c->next;
		}

		/* Create a node */
		n = (Node*)malloc(sizeof(Node));
		n->data = data;

		// Append the new node to the old tail
		n->next = c->next;

		// set the tail of the list to the new node
		c->next = n;
	}

	/* return the modified head of the list */
	return head;
}

int CompareLists(Node *headA, Node* headB)
{
	Node *a, *b;
	int a_i = 0;
	int b_i = 0;

	a = headA;
	

	while (a != NULL)
	{
		b = headB;
		b_i = 0;

		while (b != NULL)
		{
			if (a->data != b->data && a_i == b_i)
			{
				return 0;
			}
			if (a_i == b_i && ((a->next == NULL && b->next != NULL) || b->next == NULL && a->next != NULL))
			{
				return 0;
			}

			b = b->next;
			b_i++;
		}
		a = a->next;
		a_i++;
	}

	return 1;

}


// here is some test code that builds a list 
int main() 
{
	Node *headA;
	Node *headB;

	// pointer to head should be created automatically
	headA = NULL;
	headB = NULL;

	// TC
	headA = InsertNth(headA, 1, 0);
	headA = InsertNth(headA, 2, 1);
	headA = InsertNth(headA, 3, 2);
	headA = InsertNth(headA, 4, 3);

	headB = InsertNth(headB, 1, 0);
	headB = InsertNth(headB, 2, 1);
	headB = InsertNth(headB, 3, 2);
	headB = InsertNth(headB, 4, 3);

	int compare = CompareLists(headA, headB);

	return EXIT_SUCCESS;
}
