/*
Class: CSE 130 | programming in C and C++
Language: C
Program discription: 
Tell me a story.

In this century, and moment, of mania,
Tell me a story.

Make it a story of great distances, and starlight.

The name of the story will be Time,
But you must not pronounce its name.

Tell me a story of deep delight.

--Robert Penn Warren

Author: Richard Douglas
Start date: 02/11/2024
Last edit: 02/11/2024
NOTES: This program should tell you a story. I hope it's okay I took the liberty of having some fun with it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct Reader{
    char name[21];
    int age;
    char fav_color[11];
    char *origin;
    char *sign;
    char sidekick[8];
    int keys;
    int tokens;
};

char earth_poem[] =     "A seed germinates\n"
                        "Nursed by the ground beneath\n"
                        "A hero is born"
;
char wind_poem[] =      "May breath breathe out life\n"
                        "Currents of air will fill your mast\n"
                        "A hero is born"
;
char water_poem[] =     "All is quenched by me\n"
                        "Drops from Adam's reservoir\n"
                        "A hero is born"
;
char fire_poem[] =      "Energy is light\n"
                        "Destiny calls on a flame\n"
                        "A hero is born"
;
char earth_sign[] =
    "             .:----==---.               \n"   
    "           :-====-:-==+=--=:.           \n"    
    "         :--=====--=====-=::::.         \n"    
    "        --::=-:-==+++==---::-:-:        \n"    
    "       --::::--===+++==--====:--:       \n"    
    "      .+::::-=+++++++=-:::----::-.      \n"    
    "      -+--===+++++++=-:::::::---=:      \n"    
    "      -+=====++++++++=----:::::==:      \n"    
    "      .*++==---=++++++++==::::-=+.      \n"    
    "       -*++-::::--==+++++=-::-=+-       \n"    
    "        =*+=--::::==++++==::-==-        \n"    
    "         :+*+=::-==++++++==++=:         \n"    
    "           :=+===++++++++++=:           \n"    
    "             .:--=++++==-:              \n"
;
char wind_sign[] =
"                         ,.::`:,                      \n"         
"                        /       :              .....  \n"      
"                       ::        :           :`      :\n"
"                                 :       ;           )\n"
"                               .:       /          .: \n"
"             ~~~~~~~~~~~~~~~~```                 .:   \n"  
"           .....................................::    \n"     
"                            ,,,,,,,,,,,        \n"     
"                   `````````````````````````:  \n"    
"                                             ) \n" 
"                                            :  \n"  
"                                 :         :   \n"
"                                  :......:`    \n"
;
char water_sign[] = 
      "                  \n"
      "        ::        \n"
      "       --.:       \n"
      "      =*: :=      \n"
      "     ++=..::+     \n"
      "   .=-+-..-.:+    \n"
      "  .#=:+:..-=:#*   \n"
      "  *#++=-::-=++#+  \n"
      " :#-.-=----====#. \n"
      " .*.  :-----::00. \n"
      "  -+:  ..:::-+#-  \n"
      "   :+**++****+.   \n"
      "     .:-==-:      \n"
      "                  \n"
;
char fire_sign[] = 
"                             .:'    .'^,I+],                                                            .:'    .' ,I+],                               \n"
"                             )c}_~_{ /uYQC)^                            .                               )c}_~_{  uY0C)^                            .  \n"
"                        `.  `cwUzzULOmpdL  ^      .   `       ,`        I:                        ` .  `cwUzzUC0mpdL ^      .    `      ,`         I: \n"
"    .^      .^        ':+]I ,ndm0OZwpkbLj?i,`.'``:`  `[I'''   ~         ^(I    .^      .^        ':_]I ,ndm0OZwpkbLj?!,`.'``:`  `[I''' <[~         ^)I\n"
"I'':<:       il.    .`,l[nn~:fpbqqpdkkOv)_ilIl>~_^  ^t}!Il</r+.          {jI'':<:       il.    .`,l[nn~:fpbqqpdkkZv)_ilIl>~_^  ^t}!Il</r+.          {r\n"
"(l:~/I       ^|?l   `^ <(u  +)mkbdbkhpJj{-++-{()^  ,uj]__[nz>'.         .<Y|I:~/I       ^|-l ``^ I<(u|c+(mkbdbkhqJj{-++-{()^  ,uj]__[nz>'.         .<X\n"
"c]<}vi        ?v1_!IIl!]tX>ux}CdkkkkbOYr(}[{/nx:  ,cX  {(xL{''.          ;nX]<}vi        ?v1_!IIl!]tX>ux}LdbkkkbOYr(}[{/nx:  ,cX  {(xL{''.          ;x\n"
"Lf{fU~        Icv|[~<~~]rC[<CtnmpdbbwLXr/|  zJ-  `tQnjt/xY0}`.           `1Qf{fU~        Icv|[~<~~]rC]>CtnmpdbbwLXr/|  zJ-  `tQnjt/xY0}`.           ^{\n"
"JJjcL_       .:{Uzf1]???tJz:}LjUmmwqZJcj//rzQz:'`>ULcvnxvUOU~^'.      . .`>UJjcL_       ':{Uzf1]???tJz:}LjUmmwqZJcj//rzQz:''>ULcunxvUOU~^'.      . .`>\n"
"(cJJ0]^.     `;<|JUn   }1v0/  fCuLOQQ0JvjjrvJZt,^:-JQYzXccXJZL(i,^`'.  ...`;)zJJ0]^'     `;<|JUn   }1v0/ fCuLOQQ0JvjjrvJZt,^:-JQYzXccXJOL|i,^`'.  ..`;\n"
">~f0Z(;^'.  . l_{cQUv/(()tJQ-IYUXQCUJJcnxvYLZ(:,i_zZJYYUYXYU0ZU/-!:^`..`'',>~f0Z(;^'.  .  _{cQUv/(()tJQ-IYUXQCUJJcnxvYLZ(:,i_zZJYYUYXYU0ZU/-!:^`..`'',\n"
"::lnwx<;^`..`;_fULLJXx/    Ox;)LYCJXzUzccXJOO)l;<+fZQJYYUUYYYJ0ZQc  I,^ ^' ::lnwx<;^` .`;_fULLJXx/    Ox;)LYCJXzUzccXJOO)l;<_fZQJYYUUUYYJ0ZQc   ,^ ^'^\n"
"` ,+QJ}i:,''^!fQLJYXvxtt/tu0Xi_CUCUcuYXXYULmJ[ii~_1LZQCUYYUUUYYJQ00J  I;:`^`  ,+QJ[i:,''^!fQLJYXvxft/tu0Xi_CUJUcuYXXUULmJ[ii~_1LZQCUYUUUUYYUQ00J I;:`^\n"
"'`^;t0r-l;   <YLXcuxrffffjXOv!+JUUXunUYUJCOmx-<~~_{umOQLJYYYUUUYUCJQQt+>I^ ``^;t0r-l;   <YLXvuxrffffjXOv!+JUUXunUUUJCOmx->~~_{umOQLJUYYUUUYUCJQ0t+>I  \n"
"''` +JL  lI  !vLcnrjjjfjjvQQ);[LzXvxvJJCLQm0|+<+~_{rOZ0QLCUUYUUYUCJJOz{?!,,`'`  JL  lI   vLcnrjjjjfjvQQ)I[LzXcxvJJCLQm0|+<+~_{rOZ0QLCUUYUUYUCUJOz{?!,,\n"
"''`^;/ZJ|+il::}LUnxxrjjxc0Ot~;/CvvuxcJCLQOwC(+<_~_{nZZ0QLJJUYUUUJUC0Qu|-I:,'.`^;/ZJ|+il::}LUnxxrjjxc0Of~;/CvvuxcJCLQ0wC(+<_~_{nZZ0QLJJJYUUUJUC0Qn   :,\n"
"''`^,_JqJ)_<iII)LJvnxxvUZQ/-lizYnunxcCCLQOmOt?~__-1XmOQJzXJUYUJUULOLn(_l;:^.'`^,_JqC)_<iII)LJvnxxvUZQ/-lizYnunxcCCLQOmOt?~__-1XmOQJzXJUYUJUULOLn(_!;:^\n"
"`^^^,~xmwJ|?~<!!1CQYcXLmU)_>;{LunnxxuCCLQQOwC|-?]]   QUvnXJUJUzYQOX|_!I:,`'`^^^,~xmwJ|?~<!!1CQYcXLmU)_>;{LuxnxxuCCLQQOwC|-?]]  mQYvnXJUJUzYQOX|_!I:,`'\n"
":;;I>_fZOOJ  ~>ii}UZOOZn]~<IicYrxxrrjzCCLLQOmLt}1{rm0XuxnUJJzvXLOv]!I: ``^,:;;Ii_fZOOJ   >ii}YZOOZn]~<IicYrxxrrjzCCLLQOmLt}1{xm0XuxnUJJzvXLOv]iI:  `^,\n"
"l!i<+1JOQJQU)_ii!>?jJU/_<<iI{LnfjjjjfjvUUJCCQ00ut  ZYnrjnXXuncUZY]!I ``,:;Il!i<+)JOQJQU)_ii!>?jJU/_<<iI{LnfjjjjfjcUUJCCQ00ut  ZYnrjnXXuncUZY]!I,``,:;I\n"
">~?|uL0LUcYQf_!I;I!<[{_~><iljCrttfffft/xzXXXUUJOUvOQujfjxnrjxvCm/>l,' ;;Ili>~?|uQ0LUcYQt_!I;I!<[{_~><i!jCrttfffft/xzXXXUUJOUvOQujfjxnrjxvCm/>l,' ;;Il!\n"
" nCQLJYcxxYL(<I;^,;l<+<~i>>ixJr/  tttt  tvcvccuCZ0ZXrftfjjffjnLZ(iI``::;!>+{nCQLJYcxxYL(<I;^,;l~+<~i>>ixJr/  tttt  fvcvccuCZ0ZXrftfjjffjnLO(iI^`::;l>+\n"
"UOUccujtfvLr+l,   ,:i>>~i<<<fJxt        /vvvufcOOQuf//ttt//tnU0u<I^`::;l<}YOUccujtfuLr+l:    :i>>~i<<<fJxt          /vvvufcOZQuf//ttt//tnU0u<l^`::;l<}\n"
"QYnnj  tvUt~l,^..  :li<~i<<<)Ynf  (||     rXzv/xCQJrt  /    /rvcLfi;`  ,,Ii{QYnnr   vUt~l,^..^:l!>~i<<<)Ynf  (||  |||rXzv/xCQJrt       /rvcLfi;` ,,Ii}\n"
"Ucjj|(/vu]!;^`. `^^:l!<~i<~<?nuf ))(|    /rCQJ/fzJXf/|||((|||fxruUf>,`, :l-Ycjj|(/vu]!; `. `^^:l!<<i~~<?nut   )(|    rCQJ/fzJXf/|||((|||fxruUf>,`, :l-\n"
"fctt1)rr>;,`'  .`` Ili<<i<_<_  /(1{1(|  frYmqZj/nXu/|))){1))(/jttjcr~,^   !fctt))rj>;:`'  .`` Ili<<i<_<_   (1{1(|   rYmqZj/xXu/|))){1)((/jttjcr~,^  :i\n"
"~xt  [j?::'.   ''^:l!><<><_++)x  ][}(  jnYOwwwx|fvj(){{}[}{1)  |((  x?:^  ,~xt  j?::'.   ''`:l!>~<><_++)x  ][}(   nYOwwwx|fvj(){{}[}{1)   |((  x?:^^^:\n"
",-j11-(+ ^    ..`,li>~~~~~_-+(f1?_-[)/fnYQQQOOr1/n  }]]--]]{((()1{{1  };^^^,-j11-  ^    ..`,lii~~~~~_-+(f1?_-[)  nYQQQOOr1/n   ]]--]]{)(()1{{1   };^^^\n"
"^,[([_-_''     '`,i~_?--++_?]  ?~>~?1/rzJJUJLL/](f{]-_+~~_?}}[[[[]?][1/]: `^,[([_-_`'    .'^,i~_?--++_?]  ?~>~]1/rzJJUJLL/](f{]-_+~~_?}}[[[[]?][1/]:^`\n"
".`l[-+i+'      .^![1|  (1{{)){?<lli-1/nXcvvzUX{~}(?_~>i!i>______+~~+-?[1l^'.`l[-+i+'      .`i[1(  (1{{)){-<lli-1/nXcvvzUX{~}(?_~>i!i>______+~~+-?[1l^'\n"
" .,~>i;!'      .i?}]]][[}{1[_~!;,,l+}  xjffxvn?!+[~>!lI::Iiii!!!!!i><~-_ .  .,~>i;!'      .i?}]]][[}{1[_<!;,,l+}  xjffxvn?!+[~>!lI::Iiii!!!!!i><~-_ . \n"
"  ^l ,`,.      ,lIlIIl!ii<il;,^'.`:>-)|(111(/ +,;>i;:,^`'` :, ,,:;Ill!I'     ^l ,`,.      ,lIlIIl!ii<iI;,^'.`:>-(|(111(//+,;>i;:,^`'`    ,,:;Ill!I'   \n"
"  ''   .       ' ...'```^`'..     `;<-_~~~+_?[i. `^`..     .  .''`^`'        ''   .       ' ...'``^^`...     `;<-_~<<~_?[i. `^`..     .  .''`^`'      \n"
"                                   ' ^^```^  :`                                                               ' ^^```^  :`                            \n"
;
int name_num_assign(char *name){
    int name_num;
    scanf(name, "%d", name_num);
    return name_num;
}
char *origins[] = {"earth", "wind", "water", "fire"};

void printEllipsis(int numPeriods) {
    int i;
    for (i = 0; i < numPeriods; i++) {
        printf(".");
        fflush(stdout); // Flush the output buffer to ensure the dot is printed immediately
        sleep(1);       // Sleep for one second
    }
    printf("\n");
}
void typeMessage(char *str, int speed) {
    while (*str != '\0') {
        putchar(*str);   // Print the current character
        fflush(stdout);  // Flush the output buffer to ensure immediate printing
        usleep((80000*(rand()%5))/speed);  // Sleep for 100 milliseconds (100000 microseconds)
        str++;           // Move to the next character in the string
    }
}
int main()
{   
    system("clear");
    struct Reader character;
    // messages
    char current_message[1000];
    sprintf(current_message, "A mysterious force has poisoned our world... Little time remains");
    typeMessage(current_message, 1);
    printEllipsis(3);
    sprintf(current_message, "What is your name, brave soul?\n");
    typeMessage(current_message, 1);
    scanf("%s", character.name);
    sleep(1);
    int name_num = name_num_assign(character.name);
    character.origin = origins[ name_num ];
    sprintf(current_message, "Welcome, %s - hero of %s", character.name, character.origin);
    typeMessage(current_message, 1);
    printEllipsis(3);
    switch(name_num){
        case 0:
            character.sign = earth_sign;
            break;
        case 1:
            character.sign = wind_sign;
            break;
        case 2:
            character.sign = water_sign;
            break;
        case 3:
            character.sign = fire_sign;
            break;
    }
    
    printEllipsis(5);
    // show an animation based on origin
    system("clear");
    typeMessage(character.sign, 10);
    switch(name_num){
        case 0:
            typeMessage(earth_poem, 1);
            break;
        case 1:
            typeMessage(wind_poem, 1);
            break;
        case 2:
            typeMessage(water_poem, 1);
            break;
        case 3:
            typeMessage(fire_poem, 1);
            break;
    }
    
    system("clear");

    sprintf(current_message, "Wowee Zowee! You look strong....\nLet's see if your brains are as able as your muscles.\n");
    typeMessage(current_message, 2);

    sleep(10);
}