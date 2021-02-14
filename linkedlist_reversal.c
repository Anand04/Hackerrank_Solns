/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge - Reverse Linked List 
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
Reverse a linked list and return pointer to the head
Initially head pointer argument could be NULL for empty list
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

Node* Reverse(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	else
	{
		/* traverse and print linked list */

		if (head->next == NULL)
		{
			return head;
		}
		else
		{
			Node *p = NULL;
			Node *c = NULL;
			Node *n = NULL;

			c = head;

			// Create a new reversed LL
			while (c != NULL) 
			{
				n = c->next;

				c->next = p;

				p = c;
				c = n;
			}

			return p;
		}


	}
}


// here is some test code that builds a list 
int main() 
{
	Node *head;

	// pointer to head should be created automatically
	head = NULL;

	// TC1
	head = InsertNth(head, 1, 0);
	head = InsertNth(head, 2, 1);
	ReversePrint(head); // 21
	head = NULL;

	// TC2
	head = InsertNth(head, 2, 0);
	head = InsertNth(head, 1, 1);
	head = InsertNth(head, 4, 2);
	head = InsertNth(head, 5, 3);
	ReversePrint(head); // 5412

	return EXIT_SUCCESS;
}
