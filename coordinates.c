#include "coordenadas.h"
#include <math.h>
#include <stdio.h>

/// multiplica um vetor por um escalar
/// este é um exemplo entregue pronto pra você ;)
vetor multiplicaPorEscalar(vetor v, escalar alpha)
{
    vetor resultado =
    {
        v.x * alpha,
        v.y * alpha,
        v.z * alpha,
        v.w * alpha
    };
    return resultado;
}

vetor somaVetorComVetor(vetor v, vetor u)
{
    vetor resultado =
    {
        v.x +u.x,
        v.y +u.y,
        v.z +u.z,
        v.w +u.w
    };

    return resultado;
}

vetor diferencaVetorComVetor(vetor v, vetor u)
{
    vetor resultado =
    {
        v.x -u.x,
        v.y -u.y,
        v.z -u.z,
        v.w -u.w
    };
    return resultado;
}

vetor diferencaEntrePontos(ponto p, ponto q)
{
    vetor resultado =
    {
        p.x -q.x,
        p.y -q.y,
        p.z -q.z,
        p.w -q.w
    };
    return resultado;
}

ponto somaPontoComVetor(ponto p, vetor v)
{
    ponto resultado = 
    {
        v.x +p.x,
        v.y +p.y,
        v.z +p.z,
        v.w +p.w
    };
    return resultado;
}

escalar normaDoVetor(vetor v)
{
    escalar resultado = sqrt(
        (v.x *v.x)+
        (v.y *v.y)+
        (v.z*v.z)
    );
    return resultado;
}

vetor normalizado(vetor v)
{
    vetor resultado =
    {
        v.x/normaDoVetor(v),
        v.y/normaDoVetor(v),
        v.z /normaDoVetor(v),
        v.w
    };
    return resultado;
}

escalar distanciaEntrePontos(ponto p, ponto q)
{
    escalar resultado = sqrt(
        (p.x -q.x)+
        (p.y -q.y)+
        (p.z-q.z)
    );
    return resultado;
}

escalar produtoEscalar(vetor v, vetor u)
{
    escalar resultado =
    (
        (v.x *u.x)+
        (v.y *u.y)+
        (v.z *u.z)+
        (v.w *u.w)
    );
    return resultado;
}

vetor produtoVetorial(vetor v, vetor u)
{
    //TODO: implementar
    // Produto vetorial só faz sentido em 3D
    // Ignorar a componente "w" de "v" e "u"
    // Como o resultado é um vetor, o "w" dele deve ser 0
    vetor resultado = v;
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#30
escalar anguloEntreVetores(vetor v, vetor u)
{
    //TODO: implementar
    escalar resultado = 0;
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#22
ponto combinacaoAfim2Pontos(ponto p, ponto q, escalar alpha)
{
    //TODO: implementar
    ponto resultado = p;
    return resultado;
}

/// Imprime um vetor ou ponto no terminal
/// Uso:
///   vetor r = somaVetorComVetor(a, b);
///   imprime("vetor r", r);
void imprime(struct coordenadas c, char* nome)
{
    printf("%s = { %.2f, %.2f, %.2f, %.2f }\n", nome, c.x, c.y, c.z, c.w);
}
