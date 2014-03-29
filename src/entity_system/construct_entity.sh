#!/bin/bash

ENTITY_H="entity.h"
TMP_FD_FILE=.entity_forward_decls.tmp
TMP_PM_FILE=.entity_public_members.tmp

FORWARD_DECLS_FLAG="ENTITY_CONSTRUCT_FORWARD_DECLS"
PUBLIC_MEMBERS_FLAG="ENTITY_CONSTRUCT_PUBLIC_MEMBERS"

touch $TMP_FD_FILE
for i in components/*.h; do
  echo 'class ' `echo $i | sed -e 's/^[^/]*\///g' -e 's/.h$//' | gsed -e 's/_\(.\)/\U\1/g' -e 's/^\(.\)/\U\1/' -e 's/$/;/'` >> $TMP_FD_FILE
done

touch $TMP_PM_FILE
for i in components/*.h; do
  echo `echo $i | sed -e 's/^[^/]*\///g' -e 's/.h$//' | gsed -e 's/_\(.\)/\U\1/g' -e 's/^\(.\)/\U\1/' -e 's/$/*/'` `echo $i | sed -e 's/^[^/]*\///g' -e 's/.h$/;/'` >> $TMP_PM_FILE
done

inject ${FORWARD_DECLS_FLAG}_START  ${FORWARD_DECLS_FLAG}_END  $TMP_FD_FILE $ENTITY_H
inject ${PUBLIC_MEMBERS_FLAG}_START ${PUBLIC_MEMBERS_FLAG}_END $TMP_PM_FILE $ENTITY_H

rm $TMP_FD_FILE
rm $TMP_PM_FILE

exit 0

