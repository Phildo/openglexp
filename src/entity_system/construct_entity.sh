#!/bin/bash

TMP_FILE=.ENTITY_CONSTRUCTION.tmp

function fileToUnder()
{
  echo $1 | sed -e 's/^[^/]*\///g' -e 's/.h$//'
}
function underToCamel()
{
  echo $1 | gsed -e 's/_\(.\)/\U\1/g' -e 's/^\(.\)/\U\1/'
}


#
#CONSTRUCT ENTITY
#
ENTITY_H_FILE="entity.h"

ENTITY_H_FORWARD_DECLARATIONS="ECS_CONSTRUCT_C_FORWARD_DECLS"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "class $CAMEL;"  >> $TMP_FILE
done
inject ${ENTITY_H_FORWARD_DECLARATIONS}_START  ${ENTITY_H_FORWARD_DECLARATIONS}_END  $TMP_FILE $ENTITY_H_FILE
rm $TMP_FILE

ENTITY_H_PUBLIC_MEMBERS="ECS_CONSTRUCT_PUBLIC_C_MEMBERS"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "$CAMEL* $UNDER;" >> $TMP_FILE
done
inject ${ENTITY_H_PUBLIC_MEMBERS}_START ${ENTITY_H_PUBLIC_MEMBERS}_END $TMP_FILE $ENTITY_H_FILE
rm $TMP_FILE


#
#CONSTRUCT ENTITY_POOL
#
ENTITY_POOL_H_FILE="entity_pool.h"

ENTITY_POOL_H_C_INCLUDE="ECS_CONSTRUCT_C_INCLUDE"
touch $TMP_FILE
for i in components/*.h; do
  echo "#include \"$i\"" >> $TMP_FILE
done
inject ${ENTITY_POOL_H_C_INCLUDE}_START ${ENTITY_POOL_H_C_INCLUDE}_END $TMP_FILE $ENTITY_POOL_H_FILE
rm $TMP_FILE

ENTITY_POOL_H_C_SIGNATURE_DEF="ECS_CONSTRUCT_C_SIGNATURE_DEF"
touch $TMP_FILE
SIG_BIT=1
for i in components/*.h; do
  echo "const component_signature ComponentSig_"`fileToUnder $i`" = $SIG_BIT;" >> $TMP_FILE
  SIG_BIT=$(($SIG_BIT * 2))
done
inject ${ENTITY_POOL_H_C_SIGNATURE_DEF}_START ${ENTITY_POOL_H_C_SIGNATURE_DEF}_END $TMP_FILE $ENTITY_POOL_H_FILE
rm $TMP_FILE

ENTITY_POOL_H_C_SIGNATURE_DEF="ECS_CONSTRUCT_C_SIGNATURE_DEF"
touch $TMP_FILE
SIG_BIT=1
for i in components/*.h; do
  echo "const component_signature ComponentSig_"`fileToUnder $i`" = $SIG_BIT;" >> $TMP_FILE
  SIG_BIT=$(($SIG_BIT * 2))
done
inject ${ENTITY_POOL_H_C_SIGNATURE_DEF}_START ${ENTITY_POOL_H_C_SIGNATURE_DEF}_END $TMP_FILE $ENTITY_POOL_H_FILE
rm $TMP_FILE

ENTITY_POOL_H_PUBLIC_C_DECL="ECS_CONSTRUCT_PUBLIC_C_DECL"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "std::vector<$CAMEL> ${UNDER}s;" >> $TMP_FILE
done
inject ${ENTITY_POOL_H_PUBLIC_C_DECL}_START ${ENTITY_POOL_H_PUBLIC_C_DECL}_END $TMP_FILE $ENTITY_POOL_H_FILE
rm $TMP_FILE

exit 0
  if(csig & ComponentSig_Physics)
  {
    PhysicsComponent pc;
    e.physicsComponentIndex = physicsComponents.size();
    pc.entityIndex = entities.size();
    physicsComponents.push_back(std::move(pc));
  }


exit 0

