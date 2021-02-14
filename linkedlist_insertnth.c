/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge - Insert a node at a specific position in a linked list
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
Insert a node at a specific position in a linked list
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

void Print(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 

	if (head == NULL)
	{
		/* print nothing */
	}
	else
	{
		/* traverse and print linked list */

		if (head->next == NULL)
		{
			printf("%d", head->data);
		}
		else
		{
			Node* n;

			n = head; // start at top of list

			while (n != (void*)0) {

				printf("%d", n->data);

				/* enumerate through each next Node pointer
				until the end of list (n is NULL) */

				n = n->next;

			}
		}


	}
}

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


// here is some test code that builds a list 
int main() 
{
	/* Test code to build a test linked list to test the print out of it
	   using a neat array operation to fill the same dynamic structure defintion */

	Node *lst;
	Node *c0, *c1, *c2, *c3, *c4, *c5;
	Node* c;
	Node *head;
	//int elements = 6;

	// pointer to head should be created automatically
	head = NULL;
	
	/*
		5
		3 0
		5 1
		4 2
		2 3
		10 1

		expected output: 310542
		3
		10
		5
		4
		2

	*/

	/* Use our test structure to test the printing out of what we put into our linked list */
	//Print(n);

	/*head = (Node*)malloc(sizeof(Node));
	head->data = 5;
	head->next = NULL;*/

	//head = InsertNth(head, 5, NULL);

	// TC1
	head = InsertNth(head, 3, 0);
	head = InsertNth(head, 5, 1);
	head = InsertNth(head, 4, 2);
	head = InsertNth(head, 2, 3);
	head = InsertNth(head, 10, 1);

	//TC2
	//head = InsertNth(head, 3, 0);
	//head = InsertNth(head, 5, 1);
	//head = InsertNth(head, 4, 2);
	//head = InsertNth(head, 10, 1);


	//InsertNth(head, 5, 0);
	//InsertNth(head, 7, 1);
	Print(head);

	return EXIT_SUCCESS;
}
