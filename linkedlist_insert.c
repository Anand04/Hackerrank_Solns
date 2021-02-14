/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge - Insert a Node at the Tail of a Linked List
* Date: 15/12/2016
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
Insert Node at the end of a linked list
head pointer input could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
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

Node* Insert(Node* head, int data)
{
	Node *n, *c, *p;
	int elements = 0;

	/* Create a node */
	n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL; // terminate end of linked list

	if (head == NULL) 
	{
		head = n;
	}
	else 
	{
		if (head->next == NULL) 
		{
			head->next = n;
		}
		else 
		{
			/* find tail end of linked list */

			c = head;
			p = head;

			while (c != NULL)
			{
				p = c;
				c = c->next;
				elements++;
			}

			p->next = n;

			// could just assign quickly if we maintained a length property of the list
			//(head + elements - 1)->next = n;
		}


	}

	/* return the modified head of the list */
	return head;
}

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

				printf("%d\n", n->data);

				/* enumerate through each next Node pointer
				until the end of list (n is NULL) */

				n = n->next;

			}
		}


	}
}

// here is some test code that builds a list 
int main() 
{
	/* Test code to build a test linked list to test the print out of it
	   using a neat array operation to fill the same dynamic structure defintion */

	Node* n;
	Node* c;
	int elements = 3;
	int a_i;
	
	n = (Node*)malloc(sizeof(Node)* elements);
	a_i = -1;

	// LINKED LIST
	while (++a_i < elements) 
	{
		c = (n + a_i); // get pointer to next element in array

		/* Assign the fields of each Node instance through iteration */ 
		c->data = elements - a_i; // put some test data in the node
		c->next = n + (a_i + 1); // set the node's next item in LL to pointer in array
	}

	(n + elements - 1)->next = (void*)(0); // terminate list  (by quickly accessing the final record and terminating using a void* pointer. )

	/* Use our test structure to test the printing out of what we put into our linked list */
	Print(n);


	Insert(n, 5);
	Print(n);

	return EXIT_SUCCESS;
}
