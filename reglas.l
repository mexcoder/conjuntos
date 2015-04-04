%x tokenSet
%x setValue
%x setValue1
%x endOfInst
%x getTokens
%x interIns
%x setUn
%x SetInter

%%

<endOfInst>\n   BEGIN(INITIAL);

^set    {BEGIN(tokenSet);}

<tokenSet>[[:alnum:]]+ new_Item(yytext);
<tokenSet>:=    BEGIN(setValue);

<setValue>\{    BEGIN(setValue1);
    
<setValue1>[,[:blank:]] ;/*consumir el token*/
    
<setValue1>[a-zA-z0-9]+ addItem(yytext);
    
<setValue1>\}[[:blank:]]*   commitSet();BEGIN(endOfInst);



^union    {BEGIN(getTokens);op=UNION;PrepareTokens();}

^intersec    {BEGIN(getTokens);op=INTERSEC;printf("begin intersection\n");}

^setunion    {BEGIN(getTokens);op=setUNION;PrepareTokens();}

^setintersec    {BEGIN(getTokens);op=setINTERSEC;printf("begin intersection\n");}


<getTokens>[a-zA-Z1-9]+  addToken(yytext);
<getTokens>\n runIns(op);BEGIN(INITIAL);



^sets\n sets();

^showsets\n showsets();




<setValue,tokenSet,getTokens>\n    {errors();/*error de sintaxis*/
    BEGIN(INITIAL);}


^exit|end|close|bye exitProgram();

    /*.* error(yytext);*/

