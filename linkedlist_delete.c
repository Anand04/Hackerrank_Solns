/* Copyright © Mr Gerallt G. Franke 2016 */

/* Author: Mr Gerallt G. Franke
* Description: Hackerrank challenge - Delete a Node in a linked list
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
Delete Node at a given position in a linked list
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

		printf("\n", "");


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

Node* Delete(Node *head, int position)
{
	if (position == 0) 
	{
		head = head->next;
	}
	else 
	{
		Node *c;
		int index = 0;

		c = head;

		// get the node with positions away after the current position 
		while (++index < position)
		{
			c = c->next;
		}

		if (c->next != NULL) 
		{
			// bypass the node 
			c->next = c->next->next;
		}
		
	}

	return head;
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
	head = InsertNth(head, 3, 2);
	head = Delete(head, 0);
	
	Print(head); // 23
	head = NULL;

	// TC2
	head = InsertNth(head, 1, 0);
	head = InsertNth(head, 2, 1);
	head = InsertNth(head, 3, 2);
	head = Delete(head, 1);
	
	Print(head); // 13
	head = NULL;

	// TC3
	head = InsertNth(head, 1, 0);
	head = InsertNth(head, 2, 1);
	head = InsertNth(head, 3, 2);
	head = Delete(head, 2);

	Print(head); // 12
	head = NULL;

	// TC4
	head = InsertNth(head, 4, 0);
	head = InsertNth(head, 3, 1);
	head = InsertNth(head, 2, 2);
	head = InsertNth(head, 5, 3);
	head = InsertNth(head, 1, 4);
	head = Delete(head, 2);

	Print(head); // 4351


	return EXIT_SUCCESS;
}
