#!/bin/bash
N=$1
echo "Firmando archivo";
gpg --armor --detach-sign $1;  
echo "Verificando archivo";
gpg --verify $1.asc $1;
echo "Generando archivo Sha1";
sha1sum $1 > $1.sha1;
echo "Verificando archivo Sha1";
sha1sum $1; cat $1.sha1;
echo "Generando certificado de tiempo";
openssl ts -query -data $1 -no_nonce -sha1 -cert -out $1.tsq;
curl -H "Content-Type: application/timestamp-query" --data-binary '@'$1'.tsq' https://freetsa.org/tsr > $1.tsr;
echo "Verificando certificado de tiempo";
openssl ts -reply -in $1.tsr -text;
wget https://freetsa.org/files/tsa.crt;
wget https://freetsa.org/files/cacert.pem;
openssl ts -verify -data $1 -in $1.tsr -CAfile cacert.pem -untrusted tsa.crt;
rm -f $1.tsq tsa.crt cacert.pem;
echo "Listo";


