#!/bin/bash

EXECUTAVEL="./ordenacao"
DIRETORIO_INSTANCIAS="./instancias-num"

if [ ! -f "$EXECUTAVEL" ]; then
    echo "Erro: executável $EXECUTAVEL não encontrado. Compile primeiro com: g++ -o ordenacao main.cpp"
    exit 1
fi

echo "=== Iniciando testes com arquivos em $DIRETORIO_INSTANCIAS ==="
echo ""

for arquivo in "$DIRETORIO_INSTANCIAS"/*.in; do
    echo ">>> Testando: $arquivo"
    $EXECUTAVEL "$arquivo"
    echo ""
done

echo "=== Fim dos testes ==="
