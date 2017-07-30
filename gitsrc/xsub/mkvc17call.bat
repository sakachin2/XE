echo on
@if     exist err  del  err
@if     exist errall  del  errall
@rem set PGMS=xads xbc xcv xcvsjisc xdbcsenv xdc xdd xdepgen xdig xds xfc xff xfg xfmt xfs xci xkp xlibh xlow xmapcomp xmj xpe xts xuerpck xutf8 xver
set PGMS=xads xbc xcv xcvsjisc xdbcsenv xdc xdd xdepgen xdig xds xfc xff xfg xfmt xfs xci xkp xlibh xlow          xmj xpe xts xuerpck xutf8 xver

for %%a in (%PGMS%) do (
	call %BAT% %%a %*
 @if     exist err0  type err0>>err
 @if     exist err0  type err0>>errall
 @if     exist err0  type err0
 @if     exist err0  del  err0
    )
:ext
type err>>errall
type errall
