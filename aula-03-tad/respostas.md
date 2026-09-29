# Lista 03 — Tipos Abstratos de Dados

**Disciplina:** Estrutura de Dados I  
**Instituição:** Universidade Federal da Paraíba  
**Discente:**  Francisco Éricles Dos Santos Nascimento

---

## Questão 1 — Encapsulamento

A declaração `typedef struct ponto Ponto;` produz encapsulamento porque permite utilizar o tipo `Ponto` sem revelar seus atributos internos. Assim, o código cliente precisa utilizar as funções disponibilizadas pela interface para manipular os dados.

Duas construções recusadas pelo compilador são:

- `Ponto p;` — Erro esperado: `storage size of 'p' isn't known`.
- `p->x` — Erro esperado: `invalid use of incomplete typedef 'Ponto'`.