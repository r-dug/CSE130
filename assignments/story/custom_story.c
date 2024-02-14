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
#include <time.h>



char red[] = "\033[1;31m";

char blue[] = "\033[1;34m";

char green[] = "\033[1;32m";

char yellow[] = "\033[1;33m";

char white[] = "\033[1;37m";

char cyan[] = "\033[1;36m";

char purple[] = "\033[1;35m";

char reset[] = "\033[0m";

void *colors[7] = {&green, &white, &blue, &red, &yellow, &cyan, &purple};

void *fire_colors[4] = {&red, &yellow, &white, &purple};
void *water_colors[4] = {&cyan, &blue, &white, &purple};
void *earth_colors[4] = {&green, &green, &white, &yellow};
void *wind_colors[4] = {&white, &yellow, &cyan, &blue};

void color_reset(){
    printf("\033[0m");
}
void switch_color(char *color){
    printf("%s", color);
}
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
void *poems[4] = {&earth_poem, &wind_poem, &water_poem, &fire_poem};

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
"                                                        .:'    .' ,I+],                         \n"
"                        .                               )c}_~_{  uY0C)^                         \n"
"  .   `       ,`        I:                        ` .  `cwUzzUC0mpdL ^      .    `      ,`      \n"
"`:`  `[I'''   ~         ^(I    .^      .^        ':_]I ,ndm0OZwpkbLj?!,`.'``:`  `[I''' <[~      \n"
"_^  ^t}!Il</r+.          {jI'':<:       il.    .`,l[nn~:fpbqqpdkkZv)_ilIl>~_^  ^t}!Il</r+.      \n"
"^  ,uj]__[nz>'.         .<Y|I:~/I       ^|-l ``^ I<(u|c+(mkbdbkhqJj{-++-{()^  ,uj]__[nz>'.      \n"
"  ,cX  {(xL{''.          ;nX]<}vi        ?v1_!IIl!]tX>ux}LdbkkkbOYr(}[{/nx:  ,cX  {(xL{''.      \n"
" `tQnjt/xY0}`.           `1Qf{fU~        Icv|[~<~~]rC]>CtnmpdbbwLXr/|  zJ-  `tQnjt/xY0}`.       \n"
"`>ULcvnxvUOU~^'.      . .`>UJjcL_       ':{Uzf1]???tJz:}LjUmmwqZJcj//rzQz:''>ULcunxvUOU~^'.     \n"
"^:-JQYzXccXJZL(i,^`'.  ...`;)zJJ0]^'     `;<|JUn   }1v0/ fCuLOQQ0JvjjrvJZt,^:-JQYzXccXJOL|i,^`'.\n"
"i_zZJYYUYXYU0ZU/-!:^`..`'',>~f0Z(;^'.  .  _{cQUv/(()tJQ-IYUXQCUJJcnxvYLZ(:,i_zZJYYUYXYU0ZU/-!:^`\n"
"<+fZQJYYUUYYYJ0ZQc  I,^ ^' ::lnwx<;^` .`;_fULLJXx/    Ox;)LYCJXzUzccXJOO)l;<_fZQJYYUUUYYJ0ZQc   \n"
"~_1LZQCUYYUUUYYJQ00J  I;:`^`  ,+QJ[i:,''^!fQLJYXvxft/tu0Xi_CUJUcuYXXUULmJ[ii~_1LZQCUYUUUUYYUQ00J\n"
"~_{umOQLJYYYUUUYUCJQQt+>I^ ``^;t0r-l;   <YLXvuxrffffjXOv!+JUUXunUUUJCOmx->~~_{umOQLJUYYUUUYUCJQ0\n"
"~_{rOZ0QLCUUYUUYUCJJOz{?!,,`'`  JL  lI   vLcnrjjjjfjvQQ)I[LzXcxvJJCLQm0|+<+~_{rOZ0QLCUUYUUYUCUJO\n"
"~_{nZZ0QLJJUYUUUJUC0Qu|-I:,'.`^;/ZJ|+il::}LUnxxrjjxc0Of~;/CvvuxcJCLQ0wC(+<_~_{nZZ0QLJJJYUUUJUC0Q\n"
"_-1XmOQJzXJUYUJUULOLn(_l;:^.'`^,_JqC)_<iII)LJvnxxvUZQ/-lizYnunxcCCLQOmOt?~__-1XmOQJzXJUYUJUULOLn\n"
"]]   QUvnXJUJUzYQOX|_!I:,`'`^^^,~xmwJ|?~<!!1CQYcXLmU)_>;{LuxnxxuCCLQQOwC|-?]]  mQYvnXJUJUzYQOX|_\n"
"1{rm0XuxnUJJzvXLOv]!I: ``^,:;;Ii_fZOOJ   >ii}YZOOZn]~<IicYrxxrrjzCCLLQOmLt}1{xm0XuxnUJJzvXLOv]iI\n"
"t  ZYnrjnXXuncUZY]!I ``,:;Il!i<+)JOQJQU)_ii!>?jJU/_<<iI{LnfjjjjfjcUUJCCQ00ut  ZYnrjnXXuncUZY]!I,\n"
"UvOQujfjxnrjxvCm/>l,' ;;Ili>~?|uQ0LUcYQt_!I;I!<[{_~><i!jCrttfffft/xzXXXUUJOUvOQujfjxnrjxvCm/>l,'\n"
"Z0ZXrftfjjffjnLZ(iI``::;!>+{nCQLJYcxxYL(<I;^,;l~+<~i>>ixJr/  tttt  fvcvccuCZ0ZXrftfjjffjnLO(iI^`\n"
"OQuf//ttt//tnU0u<I^`::;l<}YOUccujtfuLr+l:    :i>>~i<<<fJxt          /vvvufcOZQuf//ttt//tnU0u<l^`\n"
"CQJrt  /    /rvcLfi;`  ,,Ii{QYnnr   vUt~l,^..^:l!>~i<<<)Ynf  (||  |||rXzv/xCQJrt       /rvcLfi;`\n"
"zJXf/|||((|||fxruUf>,`, :l-Ycjj|(/vu]!; `. `^^:l!<<i~~<?nut   )(|    rCQJ/fzJXf/|||((|||fxruUf>,\n"
"nXu/|))){1))(/jttjcr~,^   !fctt))rj>;:`'  .`` Ili<<i<_<_   (1{1(|   rYmqZj/xXu/|))){1)((/jttjcr~\n"
"fvj(){{}[}{1)  |((  x?:^  ,~xt  j?::'.   ''`:l!>~<><_++)x  ][}(   nYOwwwx|fvj(){{}[}{1)   |((  x\n"
"/n  }]]--]]{((()1{{1  };^^^,-j11-  ^    ..`,lii~~~~~_-+(f1?_-[)  nYQQQOOr1/n   ]]--]]{)(()1{{1  \n"
"(f{]-_+~~_?}}[[[[]?][1/]: `^,[([_-_`'    .'^,i~_?--++_?]  ?~>~]1/rzJJUJLL/](f{]-_+~~_?}}[[[[]?][\n"
"}(?_~>i!i>______+~~+-?[1l^'.`l[-+i+'      .`i[1(  (1{{)){-<lli-1/nXcvvzUX{~}(?_~>i!i>______+~~+-\n"
;

char *origins[] = {"\033[1;32m earth", "\033[1;37m wind", "\033[1;34m water", "\033[1;31m fire"};

char earth_riddle[] =   "There are things that you will leave more of, the more you take of them..."
                        "You place all of these on me"
                        "What am I?"
;

char wind_riddle[] =    "I move beneath the sun without leaving a shaddow"
                        "What am I?"
;

char water_riddle[] =   "I'm always running but never move"
                        "I have a mouth but never speak"
                        "I have a bed but never sleep"
                        "What am I?"
;

char fire_riddle[] =    "Feed me and I will grow"
                        "Give me water and I will shrink"
                        "What am I?"
;
void *riddle_answers[4] = {"earth", "wind", "water", "fire"};
void *riddles[4] = {&earth_riddle, &wind_riddle, &water_riddle, &fire_riddle};

struct Character{
    char name[21];
    int age;
    void *color;
    char *origin;
    char *sign;
    void *sidekick;
    int keys;
    int tokens;
    void *poem;
};

struct Sidekick{
    char name[21];
    int age;
    void *color;
    char origin[6];
    char *sign;
};


struct Sidekick Rosa = {"Rosa", 14, green, "earth"};
struct Sidekick Blake = {"Blake", 15, red, "fire"};
struct Sidekick Oliver = {"Oliver", 16, blue, "water"};
struct Sidekick Abigail = {"Abigail", 12, white, "air"};

struct Sidekick *sidekicks[4] = {&Rosa, &Blake, &Oliver, &Abigail};

void printEllipsis(int numPeriods) {
    int i;
    for (i = 0; i < numPeriods; i++) {
        printf(".");
        fflush(stdout); 
        sleep(1);       
    }
    printf("\n");
}
void typeMessage(char *str, int speed) {
    while (*str != '\0') {
        // switch_color(colors[rand()%7]);
        putchar(*str);   
        fflush(stdout);  
        usleep((80000*(rand()%5))/speed);  
        str++;           
    }
}
void crazyType(char *str) {
    while (*str != '\0') {
        switch_color(colors[rand()%7]);
        putchar(*str);   
        fflush(stdout);  
        usleep((1000*(rand()%20)));  
        str++;           
    }
}
void firePrint(char *str) {
    while (*str != '\0') {
        switch_color(fire_colors[rand()%4]);
        putchar(*str);   
        fflush(stdout);  
        str++;           
    }
}
void waterPrint(char *str) {
    while (*str != '\0') {
        switch_color(water_colors[rand()%4]);
        putchar(*str);   
        fflush(stdout);  
        str++;           
    }
}
void earthPrint(char *str) {
    while (*str != '\0') {
        switch_color(earth_colors[rand()%4]);
        putchar(*str);   
        fflush(stdout);  
        str++;           
    }
}
void windPrint(char *str) {
    while (*str != '\0') {
        switch_color(wind_colors[rand()%4]);
        putchar(*str);   
        fflush(stdout);  
        str++;           
    }
}
int main()
{   
    char current_message[1000];
    struct Character you;
    int i = 0;
    srand(time(NULL));
    system("clear");
    
    

    sprintf(current_message, "%s Your conciousness awakes in a void. \n You hear a voice, solemn and desparate...\033[0m \n\n\tA mysterious force has poisoned our world... Little time remains", purple);
    typeMessage(current_message, 2);
    printEllipsis(3);
    sprintf(current_message, "\tWhat is your name, brave soul?\n");
    typeMessage(current_message, 2);
    
    
    scanf("%s", you.name);    
    you.tokens = 20;
    you.keys = 0;
    int name_num = rand()%4;
    you.color = colors[ name_num ];
    you.origin = origins[ name_num ];
    you.poem = poems[ name_num ];

    sprintf(current_message, "\tAwaken, %s - hero of the element %s %s", you.name, you.origin, reset);
    typeMessage(current_message, 2);
    switch(name_num){
        case 0:
            you.sign = earth_sign;
            you.sidekick = sidekicks[3];
            break;
        case 1:
            you.sign = wind_sign;
            you.sidekick = sidekicks[0];
            break;
        case 2:
            you.sign = water_sign;
            you.sidekick = sidekicks[1];
            break;
        case 3:
            you.sign = fire_sign;
            you.sidekick = sidekicks[2];
            break;
    }
    printEllipsis(5);
    // show an animation based on origin
    system("clear");
    if (name_num == 0){
        while(i<1000) {
            earthPrint(you.sign);
            usleep(1000);
            system("clear");
            i++;
        }
        earthPrint(you.poem);
    }else if (name_num == 1){
        while(i<1000) {
            windPrint(you.sign);
            usleep(1000);
            system("clear");
            i++;
        }
        windPrint(you.poem);
    }else if (name_num == 2){
        while(i<1000) {
                waterPrint(you.sign);
                usleep(1000);
                system("clear");
                i++;
            }
            waterPrint(you.poem);
    }else {
        while(i<1000) {
                firePrint(you.sign);
                usleep(1000);
                system("clear");
                i++;
            }
            firePrint(you.poem);
    }

    color_reset();
    printEllipsis(5);
    system("clear");
    typeMessage(current_message, 2);
    printEllipsis(1);
    sprintf(current_message, "\tWowee Zowee! You look strong....\n\tLet's see if your brains are as able as your muscles.\n");
    while (you.keys<4 && you.tokens<0){
        // level select based on keys you have. 
        switch(you.keys){
            case(0):

            case(1):

            case(2):

            case(3):
            
            system("clear");
        }
    }
}