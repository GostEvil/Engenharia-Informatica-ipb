# Resumo dos Módulos ITN - Introdução às Redes v7.0

Este documento contém resumos de todos os módulos ITN (Introduction to Networks) baseados nos materiais da Cisco Network Academy, versão modificada por Eduardo Costa (ESTIG - IPB).

---

## Módulo 1: As Redes de Hoje

### Objetivo
Explicar os avanços nas tecnologias modernas de redes.

### Conteúdo Principal
- **Impacto das redes**: As redes conectam-nos como nunca antes, afetando profundamente as nossas vidas diárias.
- **Componentes de rede**:
  - Hosts (dispositivos finais): servidores e clientes
  - Dispositivos intermediários: switches, routers, pontos de acesso sem fios
  - Meios físicos: cabos de cobre, fibra óptica, transmissão sem fios
- **Tipos de redes**: LANs (Local Area Networks) e WANs (Wide Area Network)
- **Internet**: Coleção mundial de LANs e WANs interconectadas
- **Redes fiáveis**: Características essenciais incluem tolerância a falhas, escalabilidade, QoS (Quality of Service) e segurança
- **Tendências**: BYOD, colaboração online, comunicação por vídeo, computação em nuvem
- **Segurança**: Ameaças externas e internas, soluções de segurança em camadas
- **Profissional de TI**: Certificações CCNA e oportunidades de carreira

---

## Módulo 2: Configuração Básica do Switch e do Dispositivo Final

### Objetivo
Implementar configurações iniciais, incluindo passwords, endereçamento IP e parâmetros de gateway por omissão num switch e em dispositivos finais.

### Conteúdo Principal
- **Acesso ao Cisco IOS**: Métodos de acesso (consola, SSH, Telnet), emuladores de terminal
- **Navegação no IOS**: Modos de comando (EXEC utilizador, EXEC privilegiado, configuração global, subconfiguração)
- **Estrutura de comandos**: Sintaxe, ajuda contextual, teclas de atalho
- **Configuração básica**: Nome do dispositivo, passwords (consola, enable, VTY), encriptação de passwords, banners
- **Guardar configurações**: startup-config vs running-config, comandos copy e reload
- **Portas e endereços**: Endereços IPv4 e IPv6, máscaras de sub-rede, gateways
- **Configuração de endereços IP**: Manual e automática (DHCP), SVI (Switch Virtual Interface)
- **Verificação de conectividade**: Comandos ping e verificação de conectividade entre dispositivos

---

## Módulo 3: Protocolos e Modelos

### Objetivo
Explicar como os protocolos de rede permitem que dispositivos acedam a recursos de rede locais e remotas.

### Conteúdo Principal
- **As regras**: Elementos de comunicação (fonte, destino, canal), requisitos dos protocolos
- **Protocolos**: Funções (endereçamento, confiabilidade, controle de fluxo, sequenciamento, detecção de erros)
- **Conjuntos de protocolos**: TCP/IP (mais comum), OSI, AppleTalk, Novell NetWare
- **Organizações de estandardização**: IETF, ICANN, IEEE, ITU-T, ISO
- **Modelos de referência**: 
  - Modelo OSI (7 camadas)
  - Modelo TCP/IP (4 camadas)
- **Encapsulamento de dados**: Segmentação, sequenciamento, PDUs (dados, segmento, pacote, quadro, bits)
- **Acesso a dados**: Endereçamento L2 (MAC) e L3 (IP), comunicação na mesma rede vs redes remotas

---

## Módulo 4: Camada Física

### Objetivo
Explicar como os protocolos de camada física, serviços e meios físicos de rede possibilitam as comunicações nas redes de dados.

### Conteúdo Principal
- **Objetivo da camada física**: Transporta bits através do meio físico, codifica sinais
- **Características**: Componentes físicos, codificação (Manchester, 4B/5B, 8B/10B), sinalização
- **Largura de banda**: Capacidade do meio, latência, throughput, goodput
- **Cablagem de cobre**:
  - UTP (Unshielded Twisted Pair): mais comum, conectores RJ-45
  - STP (Shielded Twisted Pair): melhor proteção contra ruído
  - Coaxial: usado em instalações sem fios e Internet por cabo
- **Cablagem UTP**: Padrões TIA/EIA-568, categorias (Cat 3, 5, 5e, 6), cabos diretos e cruzados
- **Fibra óptica**: 
  - Modo único (single-mode): longas distâncias, lasers
  - Multimodo: LEDs, até 550 metros
  - Conectores: ST, SC, LC
- **Meio sem fios**: Propriedades, limitações (cobertura, interferência, segurança), padrões (Wi-Fi 802.11, Bluetooth, WiMAX, Zigbee)

---

## Módulo 5: Sistemas Numéricos

### Objetivo
Calcular representações entre sistemas decimais, binários e hexadecimais.

### Conteúdo Principal
- **Sistema binário**: 
  - Notação posicional binária
  - Conversão binário ↔ decimal
  - Endereços IPv4 em binário (32 bits, 4 octetos)
- **Sistema hexadecimal**:
  - Base 16 (0-9, A-F)
  - Conversão decimal ↔ hexadecimal ↔ binário
  - Endereços IPv6 (128 bits, 32 valores hexadecimais)
  - Endereços MAC (48 bits, 12 dígitos hexadecimais)

---

## Módulo 6: Camada de Ligação de Dados

### Objetivo
Explicar como o controlo de acesso ao meio na camada de ligação de dados suporta a comunicação entre redes.

### Conteúdo Principal
- **Finalidade**: Comunicações entre NICs, encapsulamento de pacotes L3 em frames L2
- **Subcamadas IEEE 802**: LLC (Logical Link Control) e MAC (Media Access Control)
- **Topologias**:
  - Físicas vs lógicas
  - WAN: ponto a ponto, hub e spoke, malha
  - LAN: estrela, barramento, anel
- **Comunicação**: Half-duplex vs full-duplex
- **Métodos de controlo de acesso**:
  - Baseado em contenção: CSMA/CD (Ethernet legacy), CSMA/CA (WLANs)
  - Controlado: acesso determinístico
- **Quadro de ligação de dados**: Cabeçalho, dados, trailer; campos (início/fim, endereçamento, tipo, controle, detecção de erros)
- **Endereços L2**: Endereços físicos (MAC), endereçamento local

---

## Módulo 7: Switching Ethernet

### Objetivo
Explicar como a Ethernet funciona numa rede comutada.

### Conteúdo Principal
- **Quadro Ethernet**: 
  - Subcamadas LLC e MAC
  - Tamanho mínimo 64 bytes, máximo 1518 bytes
  - Campos: preâmbulo, endereços MAC origem/destino, EtherType, dados, FCS
- **Endereços MAC Ethernet**:
  - 48 bits (6 bytes), expresso em hexadecimal
  - OUI (Organizational Unique Identifier) + valor do fornecedor
  - Tipos: unicast, broadcast (FF-FF-FF-FF-FF-FF), multicast
- **Tabela de endereços MAC**:
  - Aprendizagem dinâmica (examinando endereço MAC de origem)
  - Encaminhamento baseado em endereço MAC de destino
  - Filtragem de quadros
- **Métodos de comutação**:
  - Store-and-forward: verifica CRC, melhor integridade
  - Cut-through: Fast-forward e Fragment-free
- **Buffer de memória**: Por porta vs memória partilhada
- **Duplex e velocidade**: Full-duplex vs half-duplex, negociação automática, Auto-MDIX

---

## Módulo 8: Camada de Rede

### Objetivo
Explicar como a camada de rede usa os protocolos IP para comunicações confiáveis.

### Conteúdo Principal
- **Características da camada de rede**:
  - Sem ligação (connectionless)
  - Melhor esforço (best effort)
  - Independente do meio físico
  - Operações: endereçamento, encapsulamento, encaminhamento, desencapsulamento
- **Pacote IPv4**:
  - Cabeçalho: versão, serviços diferenciados, TTL, protocolo, endereços origem/destino
  - Fragmentação (IPv4 permite, causa latência)
- **Pacote IPv6**:
  - 128 bits, cabeçalho simplificado (40 bytes)
  - Não fragmenta pacotes
  - Cabeçalhos de extensão opcionais
- **Encaminhamento do host**: Decisão local vs remoto, gateway por omissão
- **Tabelas de encaminhamento do router**:
  - Rotas diretamente ligadas (C, L)
  - Rotas remotas (S, O, D)
  - Rota por omissão (S*)
  - Encaminhamento estático vs dinâmico

---

## Módulo 9: Resolução de Endereços

### Objetivo
Explicar como ARP e ND possibilitam a comunicação numa rede local.

### Conteúdo Principal
- **MAC e IP**: 
  - Endereço MAC (L2): entrega local, NIC para NIC
  - Endereço IP (L3): entrega global, origem para destino
- **ARP (Address Resolution Protocol)**:
  - Resolve endereço IPv4 para endereço MAC
  - Tabela ARP: mapeamentos IPv4 → MAC
  - Processo: consulta tabela, se não encontrar envia ARP request
  - Remoção automática após timeout
- **Descoberta de vizinhos IPv6 (ND)**:
  - Usa ICMPv6 em vez de ARP
  - Mensagens: Neighbor Solicitation (NS) e Neighbor Advertisement (NA)
  - Router Solicitation (RS) e Router Advertisement (RA)
  - Resolução de endereços IPv6 para MAC

---

## Módulo 10: Configuração Básica de um Router

### Objetivo
Implementar configurações iniciais num router e dispositivos finais.

### Conteúdo Principal
- **Configurações iniciais do router**:
  - Nome do dispositivo, passwords (enable, consola, VTY)
  - Encriptação de passwords, banner MOTD
  - Guardar configuração
- **Configurar interfaces**:
  - Comandos: interface, description, ip address, ipv6 address, no shutdown
  - Verificação: show ip interface brief, show ipv6 interface brief, show ip route
- **Gateway por omissão**:
  - Configuração em hosts (Windows, Linux, Mac)
  - Configuração em switches (ip default-gateway)
  - Necessário para comunicação com redes remotas

---

## Módulo 11: Endereçamento IPv4

### Objetivo
Calcular um esquema de sub-rede IPv4 para segmentar com eficiência a rede.

### Conteúdo Principal
- **Estrutura do endereço IPv4**:
  - 32 bits: parte de rede + parte de host
  - Máscara de sub-rede, comprimento de prefixo (/8, /16, /24, etc.)
  - Operação AND lógico para determinar rede
- **Tipos de endereços**: Unicast, broadcast, multicast
- **Endereços IPv4**:
  - Públicos vs privados (RFC 1918: 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16)
  - Especiais: loopback (127.0.0.0/8), link-local (169.254.0.0/16)
- **Segmentação de rede**: Reduzir domínios de broadcast, melhorar desempenho
- **Divisão em sub-redes**:
  - Prefixos /24, /16, /8
  - Cálculo de sub-redes e hosts
  - VLSM (Variable Length Subnet Masking): sub-rede de uma sub-rede para conservar endereços
- **Projeto estruturado**: Planeamento de endereços, atribuição por tipo de dispositivo

---

## Módulo 12: Endereçamento IPv6

### Objetivo
Implementar um esquema de endereçamento IPv6.

### Conteúdo Principal
- **Problemas do IPv4**: Esgotamento de endereços, falta de conectividade extremo a extremo, complexidade (NAT)
- **Representação IPv6**:
  - 128 bits, hexadecimal
  - Formato: x:x:x:x:x:x:x:x (8 hextets)
  - Regras: omitir zeros à esquerda, dois-pontos duplos (::)
- **Tipos de endereços IPv6**:
  - Unicast: GUA (Global Unicast Address), LLA (Link-Local Address), ULA (Unique Local Address)
  - Multicast: ff00::/8
  - Anycast
- **Configuração estática**: GUA e LLA em routers e hosts
- **Endereçamento dinâmico**:
  - SLAAC (Stateless Address Autoconfiguration)
  - SLAAC + DHCPv6 stateless
  - DHCPv6 stateful
  - EUI-64 vs IDs gerados aleatoriamente
- **Endereços multicast**: Bem conhecidos (ff02::1 all-nodes, ff02::2 all-routers), solicited-node
- **Divisão em sub-redes IPv6**: Campo ID de sub-rede separado, prefixo /64 recomendado

---

## Módulo 14: Camada de Transporte

### Objetivo
Comparar as operações dos protocolos da camada de transporte no suporte à comunicação extremo a extremo.

### Conteúdo Principal
- **Propósito**: Comunicação lógica entre aplicações, ligação entre camada de aplicação e camadas inferiores
- **Responsabilidades**: Rastrear conversas, segmentar dados, adicionar informações de cabeçalho
- **TCP (Transmission Control Protocol)**:
  - Orientado à ligação, confiável
  - Estabelece sessão, garante entrega, fornece entrega ordenada, controlo de fluxo
  - Cabeçalho: portos origem/destino, números de sequência/confirmação, flags, janela, checksum
  - Handshake triplo (SYN, SYN-ACK, ACK)
  - Término de sessão (FIN, ACK)
  - Fiabilidade: números de sequência, confirmações, retransmissão, SACK
  - Controlo de fluxo: tamanho da janela, MSS (Maximum Segment Size), prevenção de congestionamento
- **UDP (User Datagram Protocol)**:
  - Sem ligação, melhor esforço
  - Baixa sobrecarga, cabeçalho simples (4 campos)
  - Sem confirmação, sem retransmissão
  - Usado em: vídeo ao vivo, VoIP, DNS, DHCP, SNMP
- **Números de porto**:
  - Bem conhecidos (0-1023)
  - Registados (1024-49151)
  - Dinâmicos/privados (49152-65535)
  - Pares de sockets (IP + porto)

---

## Módulo 15: Camada de Aplicação

### Objetivo
Explicar o funcionamento dos protocolos da camada de aplicação no suporte a aplicações do utilizador final.

### Conteúdo Principal
- **Camadas OSI superiores**: Aplicação, apresentação (formatação, compactação, encriptação), sessão (diálogos)
- **Modelos**: Cliente-servidor vs peer-to-peer (P2P)
- **Protocolos Web**:
  - HTTP/HTTPS: GET, POST, PUT
  - Processo: URL → DNS → solicitação → resposta HTML
- **Protocolos de email**:
  - SMTP: envio (porta 25)
  - POP3: descarregamento, remove do servidor (porta 110)
  - IMAP: mantém no servidor, sincronização (porta 143)
- **Serviços de endereçamento IP**:
  - DNS: resolução de nomes, hierarquia, tipos de registos (A, AAAA, NS, MX)
  - DHCP: atribuição automática de endereços IPv4, processo (DISCOVER, OFFER, REQUEST, ACK)
- **Serviços de partilha de ficheiros**:
  - FTP: duas ligações (controle porta 21, dados porta 20)
  - SMB: partilha de ficheiros e impressoras, ligação de longo prazo

---

## Módulo 16: Fundamentos de Segurança de Rede

### Objetivo
Configurar switches e routers com recursos de proteção de dispositivo para aumentar a segurança.

### Conteúdo Principal
- **Ameaças à segurança**:
  - Tipos: roubo de informações, perda/manipulação de dados, roubo de identidade, interrupção de serviço
  - Vulnerabilidades: tecnológicas, de configuração, de política de segurança
  - Ameaças físicas: hardware, ambientais, elétricas, manutenção
- **Ataques à rede**:
  - Malware: vírus, worms, cavalos de Tróia
  - Reconhecimento: mapeamento de sistemas e serviços
  - Acesso: password attacks, exploração de confiança, redirecionamento de porta, man-in-the-middle
  - Negação de serviço: DoS, DDoS, botnets
- **Mitigação**:
  - Defesa em profundidade: VPN, firewalls, IPS, ESA/WSA, servidor AAA
  - Backups regulares
  - Atualizações e patches
  - Autenticação, autorização e accounting (AAA)
  - Firewalls: filtragem de pacotes, aplicações, URL, SPI
  - Segurança de endpoints
- **Segurança de dispositivos**:
  - Cisco AutoSecure
  - Passwords fortes, encriptação
  - SSH (6 etapas de configuração)
  - Desativar serviços não utilizados

---

## Módulo 17: Construir uma Rede Pequena

### Objetivo
Implementar um projeto de uma rede pequena para incluir routers, switches e dispositivos finais.

### Conteúdo Principal
- **Dispositivos numa rede pequena**:
  - Topologias simples, ligação WAN única
  - Seleção: custo, velocidade, capacidade de expansão, serviços do SO
  - Endereçamento IP planeado
  - Redundância para alta disponibilidade
  - Gestão de tráfego: QoS para voz e vídeo
- **Aplicações e protocolos**:
  - Aplicações de rede vs serviços da camada de aplicação
  - Protocolos comuns: SSH, HTTP/HTTPS, SMTP/POP/IMAP, FTP/SFTP, DHCP, DNS
  - Aplicações de voz e vídeo: VoIP, telefonia IP, RTP/RTCP
- **Escalar para redes maiores**:
  - Documentação, inventário, orçamento, análise de tráfego
  - Análise de protocolo, utilização da rede
- **Verificar conectividade**:
  - Ping: ICMP echo request/reply, indicadores (!, ., U)
  - Ping estendido
  - Traceroute: lista de saltos, identificação de problemas
  - Baseline da rede
- **Comandos de host e IOS**:
  - Windows: ipconfig, arp, netstat
  - Linux: ifconfig, ip address
  - MacOS: ifconfig, networksetup
  - IOS: show commands (running-config, interfaces, ip route, arp, cdp neighbors)
- **Metodologias de resolução de problemas**:
  - 6 etapas: identificar problema, teoria, testar, plano de ação, verificar, documentar
  - Escalar quando necessário
  - Comandos debug e terminal monitor
- **Cenários de resolução de problemas**:
  - Incompatibilidade duplex
  - Problemas de endereçamento IP
  - Problemas de gateway por omissão
  - Problemas de DNS

---

## Conclusão

Estes módulos cobrem os fundamentos das redes de computadores, desde conceitos básicos até implementação prática de redes pequenas. O curso ITN fornece uma base sólida para compreender como as redes funcionam, como configurar dispositivos de rede e como resolver problemas comuns.

---

*Documento gerado automaticamente com base nos materiais ITN v7.0 da Cisco Network Academy, versão modificada por Eduardo Costa (ESTIG - IPB).*
