set log=g:\src\xe\mkvc17c64dup.log
cp  %log% %log%.old
del %log%

echo "***mkvc17c ulib64*"      >>      %log%
call ulib
call mkvc17c64d  /A    2>&1 | tee -a %log%

echo "***mkvc17c xe64***"      >>      %log%
call srcxe
call mkvc17c64d  /A    2>&1 | tee -a %log%

echo "***mkvc17c xsub64*"      >>      %log%
call xsub
call mkvc17call64d /A   2>&1 | tee -a %log%

echo "***mkvc17c xp64***"      >>      %log%
call srcxp
call mkvc17c64d  /A    2>&1 | tee -a %log%

call srcxe
