%x tokenSet
%x setValue
%x setValue1
%x endOfInst
%x unionIns
%x interIns
%x setUn
%x SetInter

%%

<endOfInst>\n                   BEGIN(INITIAL);

^set                            BEGIN(tokenSet);

<tokenSet>[[:alnum:]]+          new_Item(yytext);
<tokenSet>:=                    BEGIN(setValue);

<setValue>\{                    BEGIN(setValue1);
    
<setValue1>,                    ;/*consumir el token*/
    
<setValue1>[a-zA-z0-9]+         addItem(yytext);
    
<setValue1>\}                   commitSet();
                                BEGIN(endOfInst);



^union                          {BEGIN(unionIns);printf("begin union\n");}
<unionIns>[a-zA-Z1-9,]+         printf("tokens = %s\n",yytext);BEGIN(endOfInst);



^intersec                       {BEGIN(interIns);printf("begin intersection\n");}
<interIns>[a-zA-Z1-9]+          printf("tokens  = %s\n",yytext);BEGIN(endOfInst);



^setunion                       {BEGIN(setUn);printf("begin set union\n");}
<setUn>([a-zA-Z1-9],){3}        printf("tokens  = %s\n",yytext);BEGIN(endOfInst);



^SetIntersect                   {BEGIN(setUn);printf("begin set intersec\n");}
<SetInter>([a-zA-Z1-9],){3}     printf("tokens  = %s\n",yytext);BEGIN(endOfInst);

^sets\n                         sets();

^showsets\n                     showsets();




<setValue,tokenSet>\n           errors();/*error de sintaxis*/
                                BEGIN(INITIAL);


^exit|end|close|bye             exitProgram();

    /*.* error(yytext);*/
