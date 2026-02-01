# Comandos de Rede - Guia de Referência

Este documento contém todos os comandos mencionados nos módulos ITN, organizados por contexto de uso e sistema operativo.

---

## Comandos Cisco IOS

### Navegação e Modos

#### Entrar em Modos
```bash
enable                    # Entrar no modo EXEC privilegiado (do modo EXEC utilizador)
configure terminal        # Entrar no modo de configuração global
exit                     # Sair do modo atual e voltar ao anterior
end                      # Sair de qualquer modo de configuração e voltar ao modo EXEC privilegiado
Ctrl+Z                   # Atalho para sair de qualquer modo de configuração
```

#### Navegação entre Modos
```bash
line console 0           # Entrar no modo de configuração de linha de consola
line vty 0 15            # Entrar no modo de configuração de linhas VTY (0 a 15)
interface type number    # Entrar no modo de configuração de interface
                         # Exemplo: interface gigabitEthernet 0/0/0
```

**Quando usar**: Para navegar entre os diferentes modos do IOS e configurar diferentes partes do dispositivo.

---

### Configuração Básica do Dispositivo

#### Nome do Dispositivo
```bash
hostname nome-dispositivo    # Configurar nome do dispositivo
no hostname                  # Remover nome e voltar ao padrão
```

**Quando usar**: Primeira configuração em qualquer dispositivo para identificação.

#### Passwords
```bash
enable secret password        # Configurar password do modo EXEC privilegiado
password password             # Configurar password (no modo de linha)
login                         # Ativar autenticação (no modo de linha)
service password-encryption   # Encriptar todas as passwords em texto simples
security passwords min-length # Definir comprimento mínimo de password
login block-for # attempts # within #  # Bloquear após tentativas falhadas
exec-timeout minutos segundos # Desativar sessão inativa após timeout
```

**Quando usar**: 
- `enable secret`: Sempre configurar para proteger acesso privilegiado
- `password` + `login`: Proteger acesso por consola e VTY
- `service password-encryption`: Sempre ativar para segurança
- `login block-for`: Proteger contra ataques de força bruta
- `exec-timeout`: Segurança adicional para sessões inativas

#### Banner
```bash
banner motd # mensagem #    # Criar banner do dia
```

**Quando usar**: Avisar utilizadores não autorizados sobre acesso ao dispositivo.

#### Guardar Configuração
```bash
copy running-config startup-config    # Guardar configuração atual na NVRAM
reload                                 # Reiniciar dispositivo
erase startup-config                   # Apagar configuração guardada
```

**Quando usar**: 
- `copy running-config startup-config`: Sempre após fazer alterações que quer manter
- `reload`: Reiniciar dispositivo (cuidado - causa downtime)
- `erase startup-config`: Limpar configuração e voltar aos padrões de fábrica

---

### Configuração de Interfaces

#### Configuração Básica de Interface
```bash
interface type number              # Entrar no modo de configuração de interface
description texto-descrição        # Adicionar descrição à interface
ip address endereço máscara        # Configurar endereço IPv4
ipv6 address endereço/prefixo       # Configurar endereço IPv6
no shutdown                        # Ativar interface
shutdown                           # Desativar interface
```

**Quando usar**: 
- `interface`: Sempre que precisar configurar uma interface
- `description`: Boa prática para documentar a função da interface
- `ip address` / `ipv6 address`: Configurar endereçamento na interface
- `no shutdown`: Ativar interface após configuração (por padrão estão desativadas)

#### Configuração de Link-Local IPv6
```bash
ipv6 address endereço-link-local link-local    # Configurar LLA manualmente
```

**Quando usar**: Quando precisar de um LLA específico e reconhecível.

#### Gateway por Omissão (Switch)
```bash
ip default-gateway endereço-ip    # Configurar gateway por omissão no switch
```

**Quando usar**: Em switches para permitir gestão remota de outras redes.

---

### Comandos de Verificação

#### Verificação de Interfaces
```bash
show ip interface brief           # Ver estado resumido de todas as interfaces IPv4
show ipv6 interface brief         # Ver estado resumido de todas as interfaces IPv6
show interfaces                   # Ver estatísticas detalhadas de todas as interfaces
show ip interface                 # Ver estatísticas IPv4 de todas as interfaces
show ipv6 interface               # Ver estatísticas IPv6 de todas as interfaces
show interfaces type number       # Ver detalhes de uma interface específica
```

**Quando usar**: 
- `show ip interface brief`: Verificação rápida do estado das interfaces
- `show interfaces`: Diagnóstico detalhado de problemas de interface
- `show ip interface`: Verificar configuração IPv4 específica

#### Verificação de Encaminhamento
```bash
show ip route                     # Ver tabela de encaminhamento IPv4
show ipv6 route                   # Ver tabela de encaminhamento IPv6
```

**Quando usar**: Verificar rotas conhecidas, identificar problemas de encaminhamento, verificar conectividade de rede.

#### Verificação de ARP
```bash
show ip arp                       # Ver tabela ARP no router
```

**Quando usar**: Verificar mapeamentos IPv4 → MAC, diagnosticar problemas de resolução de endereços.

#### Verificação de Configuração
```bash
show running-config              # Ver configuração atual (RAM)
show startup-config              # Ver configuração guardada (NVRAM)
show version                     # Ver versão do IOS, memória, interfaces, licenças
show protocols                   # Ver protocolos em funcionamento
```

**Quando usar**: 
- `show running-config`: Ver configuração ativa atual
- `show startup-config`: Ver configuração que será carregada no boot
- `show version`: Informações sobre hardware e software
- `show protocols`: Verificar quais protocolos estão ativos

#### Verificação de Dispositivos Vizinhos
```bash
show cdp neighbors               # Ver dispositivos Cisco Discovery Protocol vizinhos
show cdp neighbors detail        # Ver detalhes completos dos vizinhos CDP
```

**Quando usar**: 
- Descobrir topologia da rede
- Verificar conectividade com dispositivos adjacentes
- Identificar problemas de configuração IP em vizinhos

---

### Comandos de Teste de Conectividade

#### Ping
```bash
ping endereço-ip                 # Ping básico (5 pacotes)
ping                             # Ping estendido (modo interativo)
ping ipv6 endereço-ipv6          # Ping IPv6 estendido
```

**Quando usar**: 
- `ping`: Testar conectividade L3 rápida
- `ping` (estendido): Teste mais detalhado com opções personalizadas
- Verificar se dispositivo está acessível
- Diagnosticar problemas de conectividade

**Indicadores de resposta**:
- `!`: Resposta bem-sucedida
- `.`: Timeout (problema de conectividade)
- `U`: Destino inacessível

#### Traceroute
```bash
traceroute endereço-ip           # Traceroute básico
traceroute                        # Traceroute estendido (modo interativo)
traceroute ipv6 endereço-ipv6    # Traceroute IPv6
```

**Quando usar**: 
- Identificar onde está o problema no caminho para o destino
- Ver todos os saltos (hops) até ao destino
- Diagnosticar problemas de encaminhamento

**Interromper**: `Ctrl+Shift+6`

---

### Comandos de Debug e Monitorização

#### Debug
```bash
debug tipo                       # Ativar debug de um tipo específico
no debug tipo                    # Desativar debug específico
undebug all                      # Desativar todos os debugs
```

**Quando usar**: 
- Diagnosticar problemas específicos em tempo real
- **Cuidado**: Pode sobrecarregar o dispositivo
- Usar apenas quando necessário e desativar imediatamente após

#### Terminal Monitor
```bash
terminal monitor                 # Exibir mensagens de log em conexões remotas
terminal no monitor              # Parar de exibir mensagens de log
```

**Quando usar**: Ver mensagens de debug e log em conexões SSH/Telnet (por padrão não são exibidas).

---

### Configuração de Segurança

#### SSH
```bash
ip domain-name nome-domínio                    # Configurar nome de domínio
crypto key generate rsa general-keys bits     # Gerar chave RSA para SSH
username nome password password               # Criar utilizador local
login local                                    # Autenticar na base de dados local
transport input {ssh | telnet}                # Permitir SSH e/ou Telnet nas linhas VTY
```

**Quando usar**: Configurar acesso remoto seguro (SSH é preferível a Telnet).

**Processo completo**:
1. Configurar hostname único
2. Configurar domínio IP
3. Gerar chave RSA (mínimo 1024 bits)
4. Criar utilizador local
5. Configurar `login local` nas linhas VTY
6. Permitir SSH com `transport input ssh`

#### Desativar Serviços
```bash
no serviço                      # Desativar serviço específico
show ip ports all               # Ver portas abertas (IOS-XE)
show control-plane host open-ports  # Ver portas abertas (IOS anterior)
```

**Quando usar**: Desativar serviços não utilizados para segurança e conservar recursos.

---

## Comandos Windows

### Configuração e Verificação de IP

#### ipconfig
```cmd
ipconfig                        # Ver configuração IP básica
ipconfig /all                   # Ver configuração IP completa (inclui MAC)
ipconfig /release               # Libertar endereço DHCP atual
ipconfig /renew                 # Renovar endereço DHCP
ipconfig /displaydns            # Ver cache DNS
ipconfig /flushdns              # Limpar cache DNS
```

**Quando usar**: 
- `ipconfig`: Verificação rápida de endereço IP, máscara, gateway
- `ipconfig /all`: Diagnóstico completo, ver MAC address, servidores DNS
- `ipconfig /release` + `/renew`: Renovar configuração DHCP quando há problemas
- `ipconfig /displaydns`: Verificar resoluções DNS em cache
- `ipconfig /flushdns`: Limpar cache DNS quando há problemas de resolução

### Teste de Conectividade

#### ping
```cmd
ping endereço-ip                # Ping básico (4 pacotes)
ping -t endereço-ip             # Ping contínuo (até Ctrl+C)
ping -n número endereço-ip      # Especificar número de pacotes
ping -l tamanho endereço-ip     # Especificar tamanho do pacote
```

**Quando usar**: 
- Testar conectividade básica
- Verificar latência
- Diagnosticar problemas de rede
- `ping -t`: Teste contínuo para monitorizar conectividade

#### tracert
```cmd
tracert endereço-ip             # Traceroute básico
tracert -h saltos endereço-ip   # Limitar número de saltos
tracert -w timeout endereço-ip   # Especificar timeout
```

**Quando usar**: 
- Identificar onde está o problema no caminho
- Ver todos os routers no caminho até ao destino
- Diagnosticar problemas de encaminhamento

**Interromper**: `Ctrl+C`

### Resolução de Nomes

#### nslookup
```cmd
nslookup                        # Entrar em modo interativo nslookup
nslookup nome-domínio           # Resolver nome de domínio
nslookup endereço-ip            # Resolver reverso (IP para nome)
```

**Quando usar**: 
- Verificar resolução DNS
- Diagnosticar problemas de DNS
- Testar servidores DNS
- Verificar registos DNS específicos

#### netstat
```cmd
netstat                         # Ver conexões ativas
netstat -r                      # Ver tabela de encaminhamento (route print)
netstat -an                     # Ver todas as conexões e portas
netstat -b                      # Ver processos que criam conexões
```

**Quando usar**: 
- `netstat`: Ver conexões de rede ativas
- `netstat -r` ou `route print`: Ver tabela de encaminhamento do host
- `netstat -an`: Ver todas as portas abertas (segurança)
- Identificar conexões suspeitas

### ARP

#### arp
```cmd
arp -a                          # Ver tabela ARP completa
arp -d endereço-ip              # Eliminar entrada ARP específica
netsh interface ip delete arpcache  # Limpar toda a cache ARP (requer admin)
```

**Quando usar**: 
- `arp -a`: Ver mapeamentos IPv4 → MAC conhecidos
- `arp -d`: Eliminar entrada específica quando há problemas
- `netsh interface ip delete arpcache`: Limpar cache ARP completamente

---

## Comandos Linux

### Configuração e Verificação de IP

#### ifconfig
```bash
ifconfig                        # Ver configuração de todas as interfaces
ifconfig interface             # Ver configuração de interface específica
ifconfig interface up          # Ativar interface
ifconfig interface down        # Desativar interface
```

**Quando usar**: 
- Ver configuração IP, máscara, MAC
- Ativar/desativar interfaces
- Verificar estado das interfaces

#### ip
```bash
ip address                      # Ver endereços IP de todas as interfaces
ip address show interface       # Ver endereço de interface específica
ip address add endereço dev interface  # Adicionar endereço IP
ip address del endereço dev interface  # Eliminar endereço IP
ip route                        # Ver tabela de encaminhamento
```

**Quando usar**: 
- `ip address`: Comando moderno para gestão de endereços IP
- `ip route`: Ver tabela de encaminhamento
- Gestão mais avançada de rede

### Teste de Conectividade

#### ping
```bash
ping endereço-ip                # Ping contínuo (até Ctrl+C)
ping -c número endereço-ip      # Especificar número de pacotes
ping -s tamanho endereço-ip      # Especificar tamanho do pacote
```

**Quando usar**: Mesmo que Windows, mas comportamento ligeiramente diferente (contínuo por padrão).

#### traceroute
```bash
traceroute endereço-ip          # Traceroute básico
traceroute -m saltos endereço-ip # Limitar número de saltos
```

**Quando usar**: Mesmo que Windows tracert.

---

## Comandos macOS

### Configuração e Verificação de IP

#### ifconfig
```bash
ifconfig                        # Ver configuração de todas as interfaces
ifconfig interface             # Ver configuração de interface específica
```

**Quando usar**: Ver configuração IP (similar ao Linux).

#### networksetup
```bash
networksetup -listallnetworkservices    # Listar todos os serviços de rede
networksetup -getinfo "serviço"         # Obter informações de serviço específico
```

**Quando usar**: Gestão de configurações de rede através da linha de comando.

### Teste de Conectividade

#### ping
```bash
ping endereço-ip                # Ping contínuo (até Ctrl+C)
ping -c número endereço-ip      # Especificar número de pacotes
```

**Quando usar**: Mesmo que Linux.

#### traceroute
```bash
traceroute endereço-ip          # Traceroute básico
```

**Quando usar**: Mesmo que Linux/Windows.

---

## Comandos de Resolução de Problemas - Metodologia

### Abordagem Sistemática

1. **Identificar o Problema**
   - Usar comandos de verificação (`show`, `ipconfig`, `ifconfig`)
   - Falar com utilizador
   - Verificar logs

2. **Estabelecer Teoria das Causas Prováveis**
   - Analisar sintomas
   - Considerar múltiplas causas possíveis

3. **Testar a Teoria**
   - Usar comandos de teste (`ping`, `traceroute`)
   - Aplicar soluções rápidas
   - Verificar resultados

4. **Plano de Ação e Implementação**
   - Configurar correções necessárias
   - Documentar alterações

5. **Verificar Solução**
   - Testar funcionalidade completa
   - Implementar medidas preventivas

6. **Documentar**
   - Descobertas, ações, resultados
   - Para referência futura

---

## Cenários Comuns de Uso

### Verificar Conectividade Básica
```bash
# Windows/Linux/Mac
ping gateway-por-omissão
ping 8.8.8.8                    # Google DNS (teste Internet)

# Cisco IOS
ping endereço-ip
show ip interface brief         # Verificar estado das interfaces
```

### Diagnosticar Problema de Encaminhamento
```bash
# Windows
tracert endereço-destino
route print                     # Ver tabela de encaminhamento

# Linux/Mac
traceroute endereço-destino
ip route                        # Ver tabela de encaminhamento

# Cisco IOS
traceroute endereço-destino
show ip route                   # Ver tabela de encaminhamento
```

### Verificar Configuração IP
```bash
# Windows
ipconfig /all

# Linux
ifconfig
ip address

# Mac
ifconfig
networksetup -getinfo "Ethernet"

# Cisco IOS
show ip interface brief
show ipv6 interface brief
```

### Verificar Resolução DNS
```bash
# Windows/Linux/Mac
nslookup nome-domínio
ping nome-domínio               # Testar resolução

# Windows
ipconfig /displaydns            # Ver cache DNS
ipconfig /flushdns              # Limpar cache
```

### Verificar ARP
```bash
# Windows
arp -a

# Linux/Mac
arp -a

# Cisco IOS
show arp
```

### Configurar Dispositivo pela Primeira Vez
```bash
# Sequência recomendada:
enable
configure terminal
hostname NOME
enable secret PASSWORD
line console 0
password PASSWORD
login
exit
line vty 0 15
password PASSWORD
login
transport input ssh
exit
service password-encryption
banner motd # MENSAGEM #
exit
copy running-config startup-config
```

### Verificar Estado da Rede
```bash
# Cisco IOS - Visão geral
show ip interface brief
show ip route
show cdp neighbors
show version
show running-config
```

---

## Dicas Importantes

### Segurança
- **Sempre** usar SSH em vez de Telnet
- **Sempre** encriptar passwords (`service password-encryption`)
- **Sempre** usar passwords fortes
- **Sempre** configurar timeout de sessão
- **Sempre** guardar configuração após alterações

### Boas Práticas
- Usar `description` em interfaces para documentação
- Verificar configuração antes de guardar
- Fazer backup de configurações importantes
- Documentar alterações
- Testar conectividade após alterações

### Resolução de Problemas
- Começar com comandos básicos (`ping`, `show ip interface brief`)
- Verificar conectividade local antes de remoto
- Verificar configuração antes de assumir falha de hardware
- Usar `traceroute` para identificar onde está o problema
- Verificar logs e mensagens de erro

---

*Documento baseado nos materiais ITN v7.0 da Cisco Network Academy.*
