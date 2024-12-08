set log=g:\src\xe\mkvc22c64dup.log
cp  %log% %log%.old
del %log%

echo "***mkvc22c ulib64*"      >>      %log%
call ulib
call mkvc22c64d  /A    2>&1 | tee -a %log%

echo "***mkvc22c xe64***"      >>      %log%
call srcxe
call mkvc22c64d  /A    2>&1 | tee -a %log%

echo "***mkvc22c xsub64*"      >>      %log%
call xsub
call mkvc22call64d /A   2>&1 | tee -a %log%

echo "***mkvc22c xp64***"      >>      %log%
call srcxp
call mkvc22c64d  /A    2>&1 | tee -a %log%

call srcxe
