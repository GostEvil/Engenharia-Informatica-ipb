// CCNA 3 
const ALL_QUESTIONS = [
  {
    id: 1,
    question: "Qual protocolo de roteamento e capaz de escalar para redes grandes e utiliza areas nao-backbone para expansao?",
    options: ["EIGRP", "BGP", "OSPF", "RIPv2"],
    correct: [2],
    multiple: false,
    explanation: "O OSPF usa design hierarquico com uma area backbone (Area 0) e areas nao-backbone conectadas a ela, tornando-o escalavel para redes grandes. As areas nao-backbone se conectam ao backbone para permitir a expansao."
  },
  {
    id: 2,
    question: "No modelo de design hierarquico da Cisco, qual camada tem mais probabilidade de usar um switch de configuracao fixa do que as outras camadas?",
    options: ["distribuicao", "transporte", "internet", "acesso", "nucleo"],
    correct: [3],
    multiple: false,
    explanation: "A camada de acesso conecta os usuarios finais a rede. Por lidar com muitas portas mas com roteamento menos complexo, switches de configuracao fixa sao mais economicos aqui do que nas camadas de distribuicao ou nucleo."
  },
  {
    id: 3,
    question: "Um engenheiro de rede precisa obter informacoes relevantes para a operacao de dispositivos Cisco nas camadas de distribuicao e acesso. Qual comando fornece informacoes comuns relevantes para ambos os tipos de dispositivos?",
    options: ["show ip protocols", "show ip interface", "show cdp neighbors", "show port-security", "show mac-address-table"],
    correct: [2],
    multiple: false,
    explanation: "O comando 'show cdp neighbors' fornece informacoes relevantes tanto para dispositivos de camada de distribuicao quanto de acesso. 'show mac-address-table' e 'show port-security' sao mais relacionados a camada de acesso. 'show ip protocols' e 'show ip interface' sao mais relacionados as funcoes de roteamento da camada de distribuicao."
  },
  {
    id: 4,
    question: "Uma rede comutada convergiu completamente. Todos os switches tem numero de revisao VTP igual a 5. Um novo switch configurado como servidor VTP e adicionado com numero de revisao VTP igual a 4. O que ocorrera?",
    options: [
      "A rede nao compartilhara mais atualizacoes do banco de dados VLAN.",
      "O switch recem-adicionado mudara automaticamente para o modo cliente VTP.",
      "Os bancos de dados VTP permanecerão inalterados em todos os switches, exceto no recem-adicionado.",
      "Todos os switches na rede atualizarao seu banco de dados VTP para refletir o banco de dados do novo switch."
    ],
    correct: [2],
    multiple: false,
    explanation: "Quando um novo switch com numero de revisao VTP inferior (4) e adicionado a um dominio com revisao 5, o novo switch adotara o banco de dados VTP existente, pois seu numero de revisao e menor. Os demais switches mantem seus bancos de dados inalterados."
  },
  {
    id: 5,
    question: "Um administrador de rede esta adicionando uma nova VLAN para testes usando VTP. A VLAN nao esta diretamente conectada a nenhum dos servidores VTP. Qual e o melhor metodo para adicionar esta VLAN?",
    options: [
      "Alterar o switch com hosts conectados para o modo servidor VTP.",
      "Configurar uma porta nos servidores VTP para a mesma VLAN.",
      "Adicionar manualmente a VLAN ao banco de dados VLAN dos servidores VTP.",
      "Configurar interfaces no switch e reinicia-lo."
    ],
    correct: [2],
    multiple: false,
    explanation: "No VTP, as VLANs sao criadas nos servidores VTP. As informacoes de VLAN sao entao distribuidas para os clientes VTP. A melhor abordagem e adicionar manualmente a VLAN diretamente nos servidores VTP, que entao propagarao a VLAN para todos os switches no dominio."
  },
  {
    id: 6,
    question: "Quais tres pares de modos de trunking estabelecerao um link trunk funcional entre dois switches Cisco? (Escolha tres.)",
    options: [
      "dynamic desirable – dynamic desirable",
      "dynamic auto – dynamic auto",
      "dynamic desirable – dynamic auto",
      "dynamic desirable – trunk",
      "access – trunk",
      "access – dynamic auto"
    ],
    correct: [0, 2, 3],
    multiple: true,
    explanation: "O DTP gerencia a negociacao de trunk. O modo 'dynamic desirable' inicia ativamente a negociacao e tem sucesso quando o vizinho esta em modo trunk, dynamic desirable ou dynamic auto. Dois portos em 'dynamic auto' aguardam passivamente, resultando em um link de acesso (nao trunk). 'access – trunk' cria uma inconsistencia, nao um trunk valido."
  },
  {
    id: 7,
    question: "Qual padrao spanning tree foi desenvolvido pela Cisco para fornecer instancias separadas do 802.1w por VLAN?",
    options: ["RSTP", "802.1D", "MSTP", "Rapid PVST+"],
    correct: [3],
    multiple: false,
    explanation: "O Rapid PVST+ (Rapid Per-VLAN Spanning Tree Plus) e um aprimoramento proprietario da Cisco que executa uma instancia separada do 802.1w (RSTP) para cada VLAN, proporcionando convergencia mais rapida e balanceamento de carga por VLAN."
  },
  {
    id: 8,
    question: "Qual especificacao de padrao da industria foi desenvolvida para diminuir o tempo necessario para que as portas dos switches passem para o estado de encaminhamento em uma topologia comutada redundante?",
    options: ["VLSM", "PVST", "802.1Q", "RSTP", "VTP"],
    correct: [3],
    multiple: false,
    explanation: "O RSTP (Rapid Spanning Tree Protocol, IEEE 802.1w) foi desenvolvido para acelerar a transicao das portas de switch para o estado de encaminhamento. Reduz o tempo de convergencia do 802.1D original (cerca de 50 segundos) para menos de um segundo na maioria dos casos."
  },
  {
    id: 9,
    question: "Quais sao duas vantagens do EtherChannel? (Escolha duas.)",
    options: [
      "Configurar a interface EtherChannel fornece consistencia na configuracao dos links fisicos.",
      "O balanceamento de carga ocorre entre links configurados como EtherChannels diferentes.",
      "O EtherChannel usa links fisicos atualizados para fornecer largura de banda aumentada.",
      "O Spanning Tree Protocol ve os links fisicos em um EtherChannel como uma unica conexao logica.",
      "O STP garante redundancia fazendo a transicao de interfaces com falha em um EtherChannel para o estado de encaminhamento."
    ],
    correct: [0, 3],
    multiple: true,
    explanation: "A configuracao de uma interface logica EtherChannel garante consistencia na configuracao dos links fisicos. Como o EtherChannel ve os links fisicos agrupados como uma unica conexao logica, o STP nao precisa recalcular se um link fisico falhar. O EtherChannel usa portas existentes sem necessidade de upgrades de hardware."
  },
  {
    id: 10,
    question: "Quando o EtherChannel e implementado, multiplas interfaces fisicas sao agrupadas em qual tipo de conexao logica?",
    options: ["interface range", "loopback", "interface VLAN", "canal de porta (port channel)"],
    correct: [3],
    multiple: false,
    explanation: "Ao configurar o EtherChannel, as portas fisicas sao especificadas em um grupo. Uma interface logica de canal de porta (port channel) e entao criada contendo o grupo de interfaces fisicas. Toda a configuracao e aplicada a interface port channel."
  },
  {
    id: 11,
    question: "Ao configurar o EtherChannel, qual modo configurara o LACP em uma porta somente se ela receber pacotes LACP de outro dispositivo?",
    options: ["active", "auto", "desirable", "passive"],
    correct: [3],
    multiple: false,
    explanation: "'channel-group mode active' habilita o LACP incondicionalmente. 'channel-group mode passive' habilita o LACP somente se a porta receber um pacote LACP de outro dispositivo. 'desirable' habilita o PAgP incondicionalmente. 'auto' habilita o PAgP somente se receber um pacote PAgP."
  },
  {
    id: 12,
    question: "Um novo CIO solicitou a implementacao de um protocolo de roteamento dinamico de estado de link. Quais dois protocolos de roteamento atendem a esse requisito? (Escolha dois.)",
    options: ["RIPv2", "BGP", "OSPF", "IS-IS", "EIGRP"],
    correct: [2, 3],
    multiple: true,
    explanation: "OSPF (Open Shortest Path First) e IS-IS (Intermediate System to Intermediate System) sao ambos protocolos de roteamento de estado de link. Eles constroem um mapa completo da topologia e usam o algoritmo SPF de Dijkstra. RIPv2 e EIGRP sao protocolos baseados em vetor de distancia."
  },
  {
    id: 13,
    question: "O que melhor descreve a operacao dos protocolos de roteamento de vetor de distancia?",
    options: [
      "Eles usam contagem de saltos como sua unica metrica.",
      "Eles enviam atualizacoes somente quando uma nova rede e adicionada.",
      "Eles enviam suas tabelas de roteamento para vizinhos diretamente conectados.",
      "Eles inundam toda a rede com atualizacoes de roteamento."
    ],
    correct: [2],
    multiple: false,
    explanation: "Protocolos de roteamento de vetor de distancia (como RIP e EIGRP) compartilham suas tabelas de roteamento apenas com vizinhos diretamente conectados. Em contraste, protocolos de estado de link (como OSPF) inundam informacoes de estado de link por toda a rede."
  },
  {
    id: 14,
    question: "Qual declaracao define a velocidade de convergencia dos protocolos de roteamento?",
    options: [
      "O tempo que um roteador leva para formar uma adjacencia com um vizinho.",
      "O tempo que um roteador leva para aprender sobre links diretamente conectados.",
      "O tempo que um roteador leva para calcular o custo de um link.",
      "O tempo que um roteador dentro de uma rede leva para encaminhar informacoes de roteamento."
    ],
    correct: [3],
    multiple: false,
    explanation: "A velocidade de convergencia descreve quao rapidamente os roteadores de uma rede propagam e concordam com as informacoes de roteamento apos uma mudanca de topologia. Uma convergencia mais rapida significa que a rede se recupera mais rapidamente de falhas de link ou roteador."
  },
  {
    id: 15,
    question: "O que esta associado aos protocolos de roteamento de estado de link?",
    options: [
      "baixa sobrecarga de processador",
      "poison reverse",
      "loops de roteamento",
      "split horizon",
      "calculos do Shortest Path First (SPF)"
    ],
    correct: [4],
    multiple: false,
    explanation: "Protocolos de roteamento de estado de link (OSPF, IS-IS) usam o algoritmo SPF (Shortest Path First) de Dijkstra para calcular os melhores caminhos. Eles exigem mais CPU e memoria do que protocolos de vetor de distancia, mas convergem mais rapidamente e sao livres de loops."
  },
  {
    id: 16,
    question: "Quais duas informacoes estao contidas em um pacote de estado de link (LSP)? (Escolha duas.)",
    options: ["contagem de saltos", "largura de banda", "tipo de link", "atraso", "carga"],
    correct: [1, 2],
    multiple: true,
    explanation: "Os pacotes de estado de link contem informacoes sobre links diretamente conectados, incluindo o tipo de link (ponto a ponto, multi-acesso, etc.) e a largura de banda/custo do link. A contagem de saltos e uma metrica de vetor de distancia. Atraso e carga sao usados pelas metricas compostas do EIGRP."
  },
  {
    id: 17,
    question: "Qual e uma diferenca entre os protocolos de roteamento EIGRP e OSPF?",
    options: [
      "EIGRP usa contagem de saltos como metrica e OSPF usa custo como metrica.",
      "EIGRP e uma implementacao de EGP enquanto OSPF e uma implementacao de IGP.",
      "EIGRP suporta roteamento de diferentes protocolos de camada de rede, enquanto o OSPF suporta apenas protocolos baseados em IP.",
      "EIGRP suporta apenas balanceamento de carga de custo igual, enquanto o OSPF suporta balanceamento de custo igual e desigual."
    ],
    correct: [2],
    multiple: false,
    explanation: "Os Modulos Dependentes de Protocolo (PDMs) do EIGRP permitem suportar multiplos protocolos de camada de rede (IPv4, IPv6 e historicamente IPX e AppleTalk). O OSPF suporta apenas protocolos baseados em IP. Ambos EIGRP e OSPF sao IGPs. O EIGRP suporta balanceamento de carga de custo desigual via comando 'variance'; o OSPF suporta apenas custo igual."
  },
  {
    id: 18,
    question: "Qual protocolo e usado pelo EIGRP para a entrega e recebimento de pacotes EIGRP?",
    options: ["RTP (Protocolo de Transporte Confiavel)", "TCP", "UDP", "ICMP"],
    correct: [0],
    multiple: false,
    explanation: "O EIGRP usa o Protocolo de Transporte Confiavel (RTP) para garantir a entrega ordenada de pacotes EIGRP para todos os vizinhos. O RTP fornece tanto entrega confiavel quanto nao confiavel, similar ao TCP e UDP respectivamente, mas e especifico do EIGRP."
  },
  {
    id: 19,
    question: "Como a largura de banda para uma rede de destino e calculada pelo EIGRP?",
    options: [
      "a menor largura de banda configurada de qualquer interface ao longo da rota",
      "a soma das larguras de banda configuradas de todas as interfaces ao longo do caminho",
      "a maior largura de banda configurada de qualquer interface ao longo do caminho",
      "a largura de banda da interface de entrada do ultimo roteador de salto"
    ],
    correct: [0],
    multiple: false,
    explanation: "O EIGRP usa o link de menor (mais lenta) largura de banda ao longo de todo o caminho como metrica de largura de banda. Isso garante que a metrica composta reflita com precisao o link gargalo. Ele nao soma todas as larguras de banda."
  },
  {
    id: 20,
    question: "Qual comando limitaria a quantidade de largura de banda usada pelo EIGRP para trafego de controle a aproximadamente 128 Kb/s em um link de 1.544 Mb/s?",
    options: [
      "ip bandwidth-percent eigrp 100 8",
      "maximum-paths 8",
      "variance 8",
      "traffic-share balanced"
    ],
    correct: [0],
    multiple: false,
    explanation: "O comando 'ip bandwidth-percent eigrp' configura o percentual de largura de banda que o EIGRP pode usar. O padrao e 50%. Configurar 8% de 1544 Kb/s = aproximadamente 123,5 Kb/s, que equivale a 128 Kb/s. O formato do comando e: ip bandwidth-percent eigrp [numero-AS] [porcentagem]."
  },
  {
    id: 21,
    question: "Qual criterio e preferido pelo roteador para escolher um ID de roteador OSPF?",
    options: [
      "o endereco IP da interface loopback configurada mais alta no roteador",
      "o endereco IP da interface ativa mais alta no roteador",
      "o comando router-id rid",
      "o endereco IP da interface OSPF-habilitada ativa mais alta"
    ],
    correct: [2],
    multiple: false,
    explanation: "A ordem de preferencia para selecao do ID de roteador OSPF e: 1) ID de roteador configurado explicitamente via comando 'router-id rid', 2) IP mais alto de qualquer interface loopback configurada, 3) IP mais alto de qualquer interface ativa (nao precisa ser habilitada para OSPF). A configuracao explicita sempre tem prioridade."
  },
  {
    id: 22,
    question: "Qual e o efeito de inserir o comando 'network 192.168.10.1 0.0.0.0 area 0' no modo de configuracao do roteador OSPF?",
    options: [
      "A interface com endereco IPv4 192.168.10.1 sera uma interface passiva.",
      "As propagacoes OSPF incluirao a rede na interface com endereco IPv4 192.168.10.1.",
      "Este comando nao tera efeito porque usa uma mascara curinga de quatro zeros.",
      "As propagacoes OSPF incluirao o endereco IPv4 especifico 192.168.10.1."
    ],
    correct: [1],
    multiple: false,
    explanation: "A mascara curinga de quatro zeros (0.0.0.0) corresponde exatamente a um endereco IP. O comando 'network 192.168.10.1 0.0.0.0 area 0' habilita o OSPF na interface que tem exatamente esse endereco IP, e o OSPF anunciara a rede configurada nessa interface."
  },
  {
    id: 23,
    question: "Quais tres requisitos sao necessarios para que dois roteadores OSPFv2 formem adjacencia? (Escolha tres.)",
    options: [
      "Os dois roteadores devem incluir a rede do link inter-roteador em um comando de rede OSPFv2.",
      "O processo OSPFv2 deve ser habilitado na interface com o comando 'ospf process area-id'.",
      "Os temporizadores hello ou dead do OSPF em cada roteador devem corresponder.",
      "O ID de processo OSPFv2 deve ser o mesmo em cada roteador.",
      "As mascaras de sub-rede das interfaces de link devem corresponder.",
      "A interface de link em cada roteador deve ser configurada com um endereco link-local."
    ],
    correct: [0, 2, 4],
    multiple: true,
    explanation: "Para adjacencia OSPFv2: a rede deve ser incluida nas declaracoes 'network' do OSPF, os temporizadores hello/dead devem corresponder e as mascaras de sub-rede devem corresponder. O ID de processo NAO precisa corresponder (e localmente significativo). Enderecos link-local sao para OSPFv3, nao OSPFv2."
  },
  {
    id: 24,
    question: "Qual tipo de roteador OSPF conecta uma area OSPF a dominios de roteamento nao-OSPF?",
    options: ["ABR", "ASBR", "DR", "roteador backbone"],
    correct: [1],
    multiple: false,
    explanation: "Um Roteador de Fronteira de Sistema Autonomo (ASBR) fica na fronteira entre dominios OSPF e nao-OSPF. Importa informacoes de roteamento externas (de outros protocolos como BGP, EIGRP) para o OSPF usando LSAs do Tipo 5."
  },
  {
    id: 25,
    question: "Qual funcao e desempenhada por um ABR OSPF?",
    options: [
      "inundar LSAs do tipo 2 dentro de uma area",
      "originar LSAs do tipo 5 em uma area",
      "injetar LSAs do tipo 3 em uma area",
      "anunciar o ID do roteador de roteadores designados dentro de uma area"
    ],
    correct: [2],
    multiple: false,
    explanation: "Um Roteador de Fronteira de Area (ABR) conecta multiplas areas OSPF. Os ABRs geram LSAs do Tipo 3 (LSAs de Resumo) para anunciar redes de uma area em outras areas. LSAs do Tipo 2 vem dos DRs. LSAs do Tipo 5 vem dos ASBRs."
  },
  {
    id: 26,
    question: "Em qual modo o comando 'area area-id range address mask' e emitido ao configurar a sumarizacao OSPF multisarea?",
    options: [
      "modo de configuracao global",
      "modo de configuracao de roteador",
      "modo de configuracao de interface das interfaces da area 0",
      "modo de configuracao de interface de todas as interfaces participantes"
    ],
    correct: [1],
    multiple: false,
    explanation: "O comando 'area area-id range address mask' e emitido no modo de configuracao de roteador (sob o processo de roteamento OSPF). Instrui o ABR a resumir rotas de uma area especifica em um endereco de resumo antes de anunciar para outras areas."
  },
  {
    id: 27,
    question: "Qual comando pode ser usado para visualizar adjacencias OSPF com roteadores vizinhos junto com o estado de transicao?",
    options: [
      "show ip protocols",
      "show ip ospf neighbor",
      "show ip ospf interface",
      "show running-config"
    ],
    correct: [1],
    multiple: false,
    explanation: "'show ip ospf neighbor' exibe o ID do vizinho, prioridade, estado (FULL, 2WAY, etc.), temporizador dead, endereco do vizinho e interface. E o principal comando para verificar adjacencias OSPF e solucionar problemas de formacao de adjacencia."
  },
  {
    id: 28,
    question: "Qual e o termo usado para a area de uma rede que e afetada quando um dispositivo ou servico de rede experimenta problemas?",
    options: ["dominio de falha", "dominio de colisao", "dominio de broadcast", "dominio do usuario"],
    correct: [0],
    multiple: false,
    explanation: "Um dominio de falha e a parte de uma rede que e afetada quando um dispositivo ou servico de rede critico falha ou experimenta problemas. Um bom design de rede minimiza o tamanho dos dominios de falha para limitar o impacto de qualquer falha unica."
  },
  {
    id: 29,
    question: "Qual termo e usado para expressar a espessura ou altura de um switch?",
    options: ["unidade de rack (rack unit)", "densidade de portas", "tamanho do dominio", "tamanho do modulo"],
    correct: [0],
    multiple: false,
    explanation: "A espessura ou altura de um switch e medida em unidades de rack (U). Uma unidade de rack = 4,445 cm (1,75 pol.). Isso determina quanto espaco o switch ocupa em um rack de equipamentos padrao. Um switch 1U ocupa uma unidade de rack de espaco."
  },
  {
    id: 30,
    question: "Quais alteracoes de configuracao incrementarao o numero de revisao de configuracao no servidor VTP?",
    options: [
      "configurar links trunk no servidor VTP",
      "configurar ou alterar a senha VTP",
      "configurar ou alterar o nome do dominio VTP",
      "configurar ou alterar o numero de versao VTP",
      "configurar ou excluir uma VLAN ou criar um nome de VLAN"
    ],
    correct: [4],
    multiple: false,
    explanation: "O numero de revisao de configuracao VTP e incrementado somente quando alteracoes no banco de dados VLAN sao feitas: adicionando, excluindo ou renomeando VLANs. Alteracoes em links trunk, senha VTP, nome de dominio ou numero de versao nao incrementam o numero de revisao."
  },
  {
    id: 31,
    question: "Quais sao tres caracteristicas do VTP? (Escolha tres.)",
    options: [
      "No modo VTP padrao, VLANs podem ser criadas e modificadas em um switch.",
      "Switches no modo servidor VTP armazenam VLANs no banco de dados vlan.dat.",
      "Switches habilitados para VTP trocam tres tipos: rotas de resumo, anuncios de sub-rede e solicitacoes de anuncio.",
      "A configuracao do switch deve ser salva e o switch reiniciado para redefinir o numero de revisao.",
      "As atualizacoes VTP sao trocadas apenas por links trunk.",
      "Switches em diferentes dominios VTP podem trocar atualizacoes se os numeros de revisao forem iguais."
    ],
    correct: [0, 1, 4],
    multiple: true,
    explanation: "Caracteristicas VTP: O modo padrao e o modo servidor (VLANs podem ser criadas/modificadas), os servidores VTP armazenam informacoes de VLAN no vlan.dat, e as atualizacoes VTP sao enviadas apenas por links trunk. Switches em dominios VTP diferentes NAO trocam atualizacoes independentemente dos numeros de revisao."
  },
  {
    id: 32,
    question: "Qual e o proposito do arquivo vlan.dat em um switch?",
    options: [
      "Armazena a configuracao em execucao.",
      "Armazena a configuracao salva.",
      "Armazena o banco de dados VLAN.",
      "Armazena o sistema operacional."
    ],
    correct: [2],
    multiple: false,
    explanation: "O arquivo vlan.dat armazena o banco de dados VLAN contendo informacoes sobre VLANs de faixa normal (VLAN 1-1005), incluindo numeros VLAN, nomes e configuracao do modo VTP. E armazenado separadamente da configuracao em execucao/inicializacao."
  },
  {
    id: 33,
    question: "O que elimina loops de comutacao (switching loops)?",
    options: ["temporizador hold-down", "poison reverse", "Spanning Tree Protocol (STP)", "Time to Live (TTL)", "VTP"],
    correct: [2],
    multiple: false,
    explanation: "O STP (Spanning Tree Protocol) previne loops colocando portas de switch redundantes em estado de bloqueio, criando um unico caminho sem loops pela rede. Ao contrario da Camada 3 onde o TTL limita o dano de loops, a Camada 2 nao tem tal mecanismo nativo, tornando o STP essencial."
  },
  {
    id: 34,
    question: "Uma pequena rede corporativa tem seis switches Layer 2 interconectados. Todos usam o valor padrao de prioridade de ponte. Qual valor pode ser configurado na prioridade de ponte de um dos switches para garantir que ele se torne a ponte raiz?",
    options: ["1", "28672", "32768", "34816", "61440"],
    correct: [1],
    multiple: false,
    explanation: "A prioridade de ponte padrao e 32768. Os valores validos variam de 0 a 61440 em incrementos de 4096. Os valores 1 e 34816 sao invalidos (nao sao multiplos de 4096). Configurar 28672 (que e menor que o padrao 32768) fara com que esse switch se torne a ponte raiz, pois a prioridade mais baixa vence."
  },
  {
    id: 35,
    question: "Qual valor e usado para determinar qual porta em uma ponte nao-raiz se tornara a porta raiz em uma rede STP?",
    options: [
      "o endereco MAC mais alto de todas as portas no switch",
      "o endereco MAC mais baixo de todas as portas no switch",
      "o numero de revisao VTP",
      "o custo do caminho (path cost)"
    ],
    correct: [3],
    multiple: false,
    explanation: "O STP estabelece uma porta raiz em cada ponte nao-raiz. A porta raiz e a porta com o menor custo de caminho acumulado para alcançar a ponte raiz. Se os custos forem iguais, o criterio de desempate e o menor ID de ponte remetente, depois o menor ID de porta."
  },
  {
    id: 36,
    question: "Quais tres estados STP foram substituidos pelo estado de descarte (discarding) do RSTP? (Escolha tres.)",
    options: [
      "escuta (listening)",
      "aprendizado (learning)",
      "bloqueio (blocking)",
      "desabilitado (disabled)",
      "encaminhamento (forwarding)"
    ],
    correct: [0, 2, 3],
    multiple: true,
    explanation: "O RSTP substituiu tres estados STP por um unico estado 'descartando': bloqueio (porta recebe BPDUs mas nao encaminha), escuta (porta se prepara para encaminhar mas nao aprende enderecos MAC) e desabilitado (porta esta administrativamente desligada). Os estados 'aprendizado' e 'encaminhamento' permanecem no RSTP."
  },
  {
    id: 37,
    question: "Como administrador de rede, voce foi solicitado a implementar o EtherChannel na rede corporativa. Em que consiste essa configuracao?",
    options: [
      "fornecer links redundantes que bloqueiam ou encaminham trafego dinamicamente",
      "agrupar multiplas portas fisicas para aumentar a largura de banda entre dois switches",
      "agrupar dois dispositivos para compartilhar um endereco IP virtual",
      "fornecer dispositivos redundantes para permitir o fluxo de trafego em caso de falha"
    ],
    correct: [1],
    multiple: false,
    explanation: "O EtherChannel agrupa multiplas portas fisicas de switch em um link logico para aumentar a largura de banda entre dois switches. Tambem fornece redundancia, pois o link logico permanece ativo se uma porta fisica falhar. O STP o ve como um unico link e nao bloqueara nenhuma das portas fisicas."
  },
  {
    id: 38,
    question: "Qual comando iniciara o processo de agrupar duas interfaces fisicas em um grupo EtherChannel via LACP?",
    options: [
      "channel-group 2 mode auto",
      "interface port-channel 2",
      "channel-group 1 mode desirable",
      "interface range GigabitEthernet 0/4 - 5"
    ],
    correct: [3],
    multiple: false,
    explanation: "Para configurar o EtherChannel, o primeiro passo e selecionar as interfaces fisicas para agrupar usando o comando 'interface range'. O comando 'interface range GigabitEthernet 0/4 - 5' seleciona ambas as interfaces, apos o qual o comando 'channel-group mode active' pode ser aplicado para LACP."
  },
  {
    id: 39,
    question: "Um administrador de rede esta analisando os recursos suportados por diferentes FHRPs. Qual declaracao descreve um recurso associado ao GLBP?",
    options: [
      "O GLBP permite o balanceamento de carga entre roteadores.",
      "E nao proprietario.",
      "Usa um roteador virtual mestre.",
      "Funciona em conjunto com o VRRP."
    ],
    correct: [0],
    multiple: false,
    explanation: "O GLBP (Gateway Load Balancing Protocol) e um protocolo FHRP proprietario da Cisco que suporta balanceamento de carga entre um grupo de roteadores redundantes. VRRPv2 e VRRPv3 sao nao proprietarios e usam um roteador virtual mestre. HSRP e GLBP sao ambos proprietarios da Cisco."
  },
  {
    id: 40,
    question: "Um administrador de rede configurou um link EtherChannel com tres interfaces entre dois switches. Qual e o resultado se uma das tres interfaces ficar inativa?",
    options: [
      "O EtherChannel falha.",
      "As duas interfaces restantes continuam a balancear o trafego.",
      "As duas interfaces restantes se tornam links separados entre os dois switches.",
      "Uma interface se torna link ativo para dados e a outra se torna link de backup."
    ],
    correct: [1],
    multiple: false,
    explanation: "O EtherChannel fornece redundancia porque e uma unica conexao logica. A perda de um link fisico dentro do canal nao muda a topologia. As duas interfaces restantes continuam a funcionar como parte do EtherChannel e continuam a balancear o trafego."
  },
  {
    id: 41,
    question: "Quando o EtherChannel e configurado, qual modo forcara uma interface a um canal de porta sem trocar pacotes de protocolo de agregacao?",
    options: ["active", "auto", "on", "desirable"],
    correct: [2],
    multiple: false,
    explanation: "O modo 'on' forca a interface a um EtherChannel sem enviar ou receber pacotes de negociacao PAgP ou LACP. Ambos os lados devem ser configurados com o modo 'on'. Fornece EtherChannel sem a sobrecarga dos protocolos de negociacao."
  },
  {
    id: 42,
    question: "Qual termo e usado para descrever uma topologia de rede onde sub-redes de uma rede classful principal estao separadas por enderecos de uma rede classful diferente?",
    options: ["rede multi-homed", "rede convergida", "rede descontigua (discontiguous)", "rede de dados"],
    correct: [2],
    multiple: false,
    explanation: "Uma rede descontigua ocorre quando sub-redes da mesma rede classful sao separadas por sub-redes de uma rede classful diferente. Por exemplo, 10.1.0.0/24 e 10.2.0.0/24 separadas pela rede 192.168.1.0/24. Isso causa problemas com protocolos de roteamento classful como RIPv1."
  },
  {
    id: 43,
    question: "Que tipo de pacotes sao enviados quando ha uma mudanca na topologia EIGRP?",
    options: [
      "hello",
      "atualizacao delimitada disparada (triggered bounded update)",
      "reconhecimento (acknowledgment)",
      "resposta (reply)"
    ],
    correct: [1],
    multiple: false,
    explanation: "O EIGRP envia 'atualizacoes delimitadas disparadas' somente quando ha uma mudanca na topologia de roteamento, e apenas para os roteadores que precisam das informacoes (delimitadas). Isso e mais eficiente do que as atualizacoes periodicas completas da tabela de roteamento usadas pelo RIP."
  },
  {
    id: 44,
    question: "Quais tres informacoes um protocolo de roteamento de estado de link usa inicialmente como informacoes de estado de link para links conectados localmente? (Escolha tres.)",
    options: [
      "o endereco IP e a mascara de sub-rede da interface do roteador de link",
      "o tipo de link de rede",
      "o endereco IP do proximo salto do link",
      "a largura de banda do link",
      "o custo desse link"
    ],
    correct: [0, 1, 4],
    multiple: true,
    explanation: "Quando um roteador de estado de link e inicializado, ele coleta informacoes sobre seus links diretamente conectados, incluindo: o endereco IP e mascara de sub-rede da interface, o tipo de link de rede (ponto a ponto, Ethernet, etc.) e o custo desse link (usado para calculos SPF)."
  },
  {
    id: 45,
    question: "O que indica a um roteador de estado de link que um vizinho esta inacessivel?",
    options: [
      "se o roteador nao receber mais atualizacoes de roteamento",
      "se o roteador nao receber mais pacotes hello",
      "se o roteador receber uma atualizacao com contagem de saltos igual a 16",
      "se o roteador receber um LSP com informacoes previamente aprendidas"
    ],
    correct: [1],
    multiple: false,
    explanation: "Os roteadores OSPF enviam pacotes Hello em intervalos regulares para monitorar o estado dos vizinhos. Quando um roteador para de receber pacotes Hello de um vizinho antes do intervalo dead expirar, esse vizinho e considerado inacessivel e a adjacencia e encerrada."
  },
  {
    id: 46,
    question: "Quais sao tres recursos do EIGRP? (Escolha tres.)",
    options: [
      "usa o algoritmo Shortest Path First (SPF)",
      "estabelece adjacencias de vizinhanca",
      "usa o Protocolo de Transporte Confiavel (RTP)",
      "envia atualizacoes completas da tabela de roteamento periodicamente",
      "transmite atualizacoes para todos os roteadores EIGRP via broadcast",
      "suporta balanceamento de carga de custo igual e desigual"
    ],
    correct: [1, 2, 5],
    multiple: true,
    explanation: "Recursos do EIGRP: estabelece adjacencias de vizinhanca (usando pacotes Hello), usa RTP (Protocolo de Transporte Confiavel) para entrega garantida, e suporta balanceamento de carga de custo igual e desigual (via comando variance). O EIGRP usa o algoritmo DUAL (nao SPF), envia apenas atualizacoes parciais/delimitadas (nao completas) e usa multicast (nao broadcast) para 224.0.0.10."
  },
  {
    id: 47,
    question: "Que capacidade os modulos dependentes de protocolo (PDMs) fornecem ao protocolo de roteamento EIGRP?",
    options: [
      "rotear diferentes protocolos de Camada 3",
      "trocar rotas de resumo entre areas",
      "combinar rotas aprendidas de diferentes protocolos em uma unica tabela",
      "balancear carga entre protocolos de roteamento"
    ],
    correct: [0],
    multiple: false,
    explanation: "Os Modulos Dependentes de Protocolo (PDMs) do EIGRP permitem suportar multiplos protocolos de Camada 3. Historicamente, incluiam IPv4, IPv6, IPX e AppleTalk. Cada PDM trata as informacoes de roteamento especificas do seu protocolo de camada de rede."
  },
  {
    id: 48,
    question: "Qual comando configurara uma rota estatica padrao IPv6?",
    options: [
      "router(config)# ipv6 ::/64 s0/0/0",
      "router(config-rtr)# redistribute static",
      "router(config)# ipv6 route ::/0 s0/0/0",
      "router(config)# ipv6 unicast-routing"
    ],
    correct: [2],
    multiple: false,
    explanation: "A rota estatica padrao IPv6 usa '::/0' (equivalente a 0.0.0.0/0 em IPv4). A sintaxe do comando e 'ipv6 route ::/0 [proximo-salto | interface-saida]'. Um prefixo /0 corresponde a qualquer destino IPv6, tornando-o a rota padrao."
  },
  {
    id: 49,
    question: "Qual protocolo de roteamento pode ser configurado para balancear carga em caminhos com metricas desiguais atraves do uso do comando 'variance'?",
    options: ["EIGRP", "OSPF", "OSPFv3", "RIPng"],
    correct: [0],
    multiple: false,
    explanation: "O EIGRP suporta balanceamento de carga de custo desigual usando o comando 'variance'. O multiplicador de variancia permite ao EIGRP incluir rotas de sucessor viavel na tabela de roteamento se sua metrica estiver dentro do multiplicador de variancia da metrica do sucessor. O OSPF suporta apenas balanceamento de carga de custo igual."
  },
  {
    id: 50,
    question: "Quais sao dois recursos de um protocolo de roteamento de estado de link? (Escolha dois.)",
    options: [
      "Os roteadores enviam atualizacoes periodicas apenas para roteadores vizinhos.",
      "Os roteadores enviam atualizacoes disparadas em resposta a uma mudanca.",
      "Os roteadores criam uma topologia da rede usando informacoes de outros roteadores.",
      "As informacoes do banco de dados para cada roteador sao obtidas da mesma fonte.",
      "Os caminhos sao escolhidos com base no menor numero de saltos para o roteador designado."
    ],
    correct: [1, 2],
    multiple: true,
    explanation: "Protocolos de estado de link enviam atualizacoes disparadas somente quando ocorrem mudancas de topologia (nao atualizacoes periodicas para vizinhos como vetor de distancia). Eles tambem constroem um mapa topologico completo usando informacoes LSP de todos os roteadores na area, permitindo que cada roteador calcule sua propria arvore de caminho mais curto independentemente."
  },
  {
    id: 51,
    question: "O que sempre acontecera se o intervalo dead expirar antes de o roteador OSPFv2 receber um pacote hello de um roteador OSPF DROTHER adjacente?",
    options: [
      "O OSPF executara uma nova eleicao de DR/BDR.",
      "O SPF executara e determinara qual roteador vizinho esta inativo.",
      "Um novo temporizador de intervalo dead de 4 vezes o intervalo hello sera iniciado.",
      "O OSPF removera esse vizinho do banco de dados de estado de link do roteador."
    ],
    correct: [3],
    multiple: false,
    explanation: "Quando o intervalo dead expirar sem receber um hello de um vizinho, o OSPF remove esse vizinho do banco de dados de estado de link e aciona um calculo SPF. Uma eleicao DR/BDR so e executada se o roteador com falha era o DR ou BDR. O SPF determina rotas, nao estados de vizinhos."
  },
  {
    id: 52,
    question: "Em uma configuracao OSPFv2, qual e o efeito de inserir o comando 'network 192.168.1.1 0.0.0.0 area 0'?",
    options: [
      "Altera o ID do roteador para 192.168.1.1.",
      "Habilita o OSPF em todas as interfaces do roteador.",
      "Informa ao roteador qual interface ativar para o processo de roteamento OSPF.",
      "Permite que todas as redes 192.168.1.0 sejam anunciadas."
    ],
    correct: [2],
    multiple: false,
    explanation: "A mascara curinga de quatro zeros (0.0.0.0) significa que a declaracao de rede corresponde exatamente ao endereco IP 192.168.1.1. O OSPF sera habilitado somente na interface com esse endereco IP exato. A rede configurada nessa interface sera anunciada no OSPF."
  },
  {
    id: 53,
    question: "O que o custo de um link OSPF indica?",
    options: [
      "Um custo maior para um link OSPF indica um caminho mais rapido para o destino.",
      "O custo do link indica uma proporcao do valor acumulado da rota para o destino.",
      "Custo equivale a largura de banda.",
      "Um custo menor indica um caminho melhor para o destino do que um custo maior."
    ],
    correct: [3],
    multiple: false,
    explanation: "No OSPF, o custo e a metrica usada para determinar o melhor caminho. Um custo acumulado menor indica um caminho melhor (preferido) para o destino. O custo OSPF e calculado como 10^8 / largura_de_banda_interface. Maior largura de banda = menor custo = melhor caminho."
  },
  {
    id: 54,
    question: "Quais informacoes estao contidas nas LSAs do tipo 3 do OSPF?",
    options: [
      "redes alcancaveis em outras areas",
      "redes aprendidas de outros protocolos de roteamento",
      "o ID do roteador do DR para todos os roteadores na area",
      "o ID do roteador de um ASBR e a rota para alcanca-lo"
    ],
    correct: [0],
    multiple: false,
    explanation: "LSAs do Tipo 3 (LSAs de Resumo) sao gerados por ABRs para anunciar redes de uma area para outra area. Elas contem informacoes sobre redes alcancaveis em outras areas. LSAs do Tipo 5 contem rotas externas. LSAs do Tipo 4 anunciam a acessibilidade do ASBR."
  },
  {
    id: 55,
    question: "Um administrador de rede configurou um EtherChannel entre dois switches via quatro links trunk. Se a interface fisica de um dos links mudar para o estado inativo, o que acontece?",
    options: [
      "O STP fara a transicao da interface com falha para o modo de encaminhamento.",
      "O STP recalculara os links trunk restantes.",
      "O EtherChannel fara a transicao para um estado inativo.",
      "O EtherChannel permanecera funcional."
    ],
    correct: [3],
    multiple: false,
    explanation: "O EtherChannel agrupa multiplos links trunk fisicos em uma unica conexao logica. A falha de um link fisico nao muda a topologia logica, entao o STP nao precisa recalcular. O EtherChannel permanece funcional enquanto pelo menos um link fisico estiver operacional."
  },
  {
    id: 56,
    question: "Qual configuracao de modo permitiria a formacao de um link EtherChannel entre os switches SW1 e SW2 sem enviar trafego de negociacao?",
    options: [
      "SW1: on / SW2: on",
      "SW1: desirable / SW2: desirable",
      "SW1: auto / SW2: auto",
      "PortFast habilitado em ambos os switches",
      "SW1: passive / SW2: active"
    ],
    correct: [0],
    multiple: false,
    explanation: "O modo 'on' forca uma interface a um EtherChannel sem trocar pacotes de negociacao PAgP ou LACP. Ambas as extremidades devem ser configuradas com 'on'. O modo 'desirable/desirable' usa negociacao PAgP. 'auto/auto' NAO formara um EtherChannel (ambos sao passivos). 'passive/active' usa negociacao LACP."
  },
  {
    id: 57,
    question: "Quais duas declaracoes estao corretas sobre pacotes de reconhecimento (ACK) do EIGRP? (Escolha duas.)",
    options: [
      "Os pacotes sao usados para descobrir vizinhos em uma interface.",
      "Os pacotes sao enviados como unicast.",
      "Os pacotes requerem confirmacao.",
      "Os pacotes nao sao confiaveis.",
      "Os pacotes sao enviados em resposta a pacotes hello."
    ],
    correct: [1, 3],
    multiple: true,
    explanation: "Os pacotes de reconhecimento (ACK) do EIGRP sao enviados como unicast para o vizinho especifico sendo reconhecido. Eles nao sao confiaveis (nenhum reconhecimento e necessario para os proprios pacotes ACK). Os pacotes Hello sao usados para descoberta de vizinhos. Os ACKs confirmam o recebimento de mensagens EIGRP enviadas via entrega confiavel."
  },
  {
    id: 58,
    question: "Um conjunto de switches esta sendo conectado em uma topologia LAN. Qual valor de prioridade de ponte STP tornara o switch menos provavel de ser selecionado como raiz?",
    options: ["61440", "4096", "65535", "32768"],
    correct: [0],
    multiple: false,
    explanation: "O STP seleciona o switch com a MENOR prioridade de ponte como ponte raiz. Portanto, para tornar um switch MENOS provavel de se tornar raiz, configure a MAIOR prioridade valida. A maior prioridade STP valida e 61440 (o maior multiplo de 4096 que cabe em 2 bytes). Nota: 65535 nao e um valor valido, pois as prioridades devem ser multiplos de 4096."
  },
  {
    id: 59,
    question: "Um administrador de rede esta analisando os recursos suportados pelos FHRPs. Qual declaracao descreve um recurso associado ao HSRP?",
    options: [
      "O HSRP usa roteadores ativo e em espera (standby).",
      "Usa mensagens ICMP para atribuir o gateway padrao aos hosts.",
      "Permite balanceamento de carga entre um grupo de roteadores redundantes.",
      "O HSRP e nao proprietario."
    ],
    correct: [0],
    multiple: false,
    explanation: "O HSRP (Hot Standby Router Protocol) e proprietario da Cisco e usa papeis de roteador ativo e em espera. Um roteador e 'ativo' (encaminha trafego) e outro e 'em espera' (assume se o ativo falhar). O GLBP fornece balanceamento de carga. VRRPv2/v3 sao nao proprietarios com um roteador virtual mestre."
  },
  {
    id: 60,
    question: "Qual declaracao descreve uma caracteristica das rotas externas OSPF?",
    options: [
      "O custo de uma rota tipo 1 e sempre o custo externo, independentemente do custo interno.",
      "A diferenca entre tipo 1 e tipo 2 esta na forma como o custo da rota e calculado.",
      "Uma rota tipo 2 e sempre preferida em relacao a uma rota tipo 1 para o mesmo destino.",
      "Rotas externas tipo 1 e tipo 2 em redes IPv4 sao representadas na tabela por EX1 e EX2."
    ],
    correct: [1],
    multiple: false,
    explanation: "Os tipos de rotas externas OSPF diferem no calculo de custo: Tipo 2 (E2) usa apenas o custo externo (fixo, nao muda conforme se propaga pelo OSPF). Tipo 1 (E1) adiciona o custo OSPF interno ao custo externo (aumenta conforme se propaga). O Tipo 1 e preferido sobre o Tipo 2 quando ambos existem para o mesmo destino."
  },
  {
    id: 61,
    question: "Por padrao, quantas rotas de custo igual para o mesmo destino podem ser instaladas na tabela de roteamento de um roteador Cisco?",
    options: ["2", "4", "16", "32"],
    correct: [1],
    multiple: false,
    explanation: "Por padrao, o Cisco IOS instala ate 4 rotas de custo igual na tabela de roteamento para balanceamento de carga. Isso pode ser alterado com o comando 'maximum-paths'. EIGRP e OSPF suportam ate 16 caminhos de custo igual, mas o padrao e 4."
  },
  {
    id: 62,
    question: "Um roteador EIGRP perde a rota para uma rede. Sua tabela de topologia contem dois sucessores viaveis para a mesma rede. Qual acao o roteador tomara?",
    options: [
      "A melhor rota de backup alternativa e imediatamente inserida na tabela de roteamento.",
      "O roteador consultara vizinhos para obter uma rota alternativa.",
      "O algoritmo DUAL e recomputado para encontrar uma rota alternativa.",
      "O roteador usa a rota padrao."
    ],
    correct: [0],
    multiple: false,
    explanation: "O algoritmo DUAL do EIGRP mantem rotas de sucessor viavel na tabela de topologia como rotas de backup. Quando a rota primaria (sucessor) falha, o melhor sucessor viavel e imediatamente promovido para a tabela de roteamento sem consultar vizinhos ou executar novamente o DUAL. Isso permite convergencia muito rapida."
  },
  {
    id: 63,
    question: "Um administrador de rede esta analisando FHRPs. Qual e uma caracteristica do VRRPv3?",
    options: [
      "Permite o balanceamento de carga entre roteadores.",
      "O VRRPv3 e proprietario da Cisco.",
      "Suporta endereçamento IPv6 e IPv4.",
      "Funciona em conjunto com o HSRP."
    ],
    correct: [2],
    multiple: false,
    explanation: "O VRRPv3 (Virtual Router Redundancy Protocol versao 3) e um padrao aberto (nao proprietario) FHRP que suporta endereçamento IPv4 e IPv6. HSRP e GLBP sao proprietarios da Cisco. O GLBP fornece balanceamento de carga entre roteadores redundantes."
  },
  {
    id: 64,
    question: "Qual e a funcao do STP em uma rede escalavel?",
    options: [
      "Combina multiplos links trunk de switch para agir como um unico link logico para maior largura de banda.",
      "Protege a borda da rede empresarial contra atividades maliciosas.",
      "Desabilita caminhos redundantes para eliminar loops de Camada 2.",
      "Diminui o tamanho do dominio de falha para conter o impacto de falhas."
    ],
    correct: [2],
    multiple: false,
    explanation: "O STP previne loops de Camada 2 colocando portas de switch redundantes em estado de bloqueio, garantindo que haja apenas um caminho ativo entre quaisquer dois dispositivos de rede. Sem o STP, tempestades de broadcast e instabilidade na tabela MAC paralisariam a rede. O EtherChannel combina links; dominios de falha sao gerenciados pelo design da rede."
  },
  {
    id: 65,
    question: "Quando a sumarizacao automatica EIGRP deve ser desativada?",
    options: [
      "quando um roteador tem menos de cinco interfaces ativas",
      "quando um roteador tem mais de tres interfaces ativas",
      "quando uma rede contem enderecos de rede descontiguos",
      "quando um roteador nao descobriu um vizinho em tres minutos"
    ],
    correct: [2],
    multiple: false,
    explanation: "A sumarizacao automatica EIGRP resume rotas nos limites de rede classful. Em redes descontíguas (onde sub-redes da mesma rede principal sao separadas por redes diferentes), a sumarizacao automatica causa problemas de roteamento ao ocultar sub-redes especificas. O comando 'no auto-summary' deve ser usado nesses casos."
  },
  {
    id: 66,
    question: "Qual caracteristica mais influenciaria um engenheiro de design de rede a selecionar um switch multicamada (Layer 3) em vez de um switch de Camada 2?",
    options: [
      "capacidade de agregar multiplas portas para maximo throughput de dados",
      "capacidade de ter multiplos caminhos de encaminhamento pela rede comutada baseados no numero de VLAN",
      "capacidade de fornecer energia para dispositivos diretamente conectados (PoE)",
      "capacidade de construir uma tabela de roteamento"
    ],
    correct: [3],
    multiple: false,
    explanation: "Um switch multicamada (switch de Camada 3) pode realizar funcoes de roteamento e construir uma tabela de roteamento, habilitando o roteamento inter-VLAN sem um roteador externo. Agregacao de portas (EtherChannel), multiplos caminhos de encaminhamento (STP/RSTP) e PoE sao recursos tambem disponiveis em switches de Camada 2."
  },
  {
    id: 67,
    question: "Quais sao dois recursos da sumarizacao de rota interarea OSPF? (Escolha duas.)",
    options: [
      "A sumarizacao de rota resulta em alto trafego de rede e sobrecarga de roteador.",
      "Rotas dentro de uma area sao sumarizadas pelo ABR.",
      "LSAs do tipo 3 e tipo 5 sao usadas para propagar rotas sumarizadas por padrao.",
      "Os ASBRs realizam toda a sumarizacao OSPF.",
      "ABRs anunciam as rotas sumarizadas no backbone."
    ],
    correct: [1, 4],
    multiple: true,
    explanation: "Na sumarizacao interarea OSPF: os ABRs sumarizam rotas de suas areas conectadas (nao os ASBRs). As rotas de resumo sao anunciadas pelos ABRs na area backbone (Area 0) usando LSAs do Tipo 3. A sumarizacao reduz o tamanho da tabela de roteamento e a inundacao de LSAs, melhorando a eficiencia."
  },
  {
    id: 68,
    question: "Quais sao os unicos dois papeis que permitem a um roteador OSPF ser configurado para sumarizacao? (Escolha dois.)",
    options: [
      "roteador designado (DR)",
      "roteador backbone",
      "roteador interno",
      "roteador de fronteira de sistema autonomo (ASBR)",
      "roteador de fronteira de area (ABR)"
    ],
    correct: [3, 4],
    multiple: true,
    explanation: "A sumarizacao OSPF so pode ser feita nos limites de area ou de SA. Os ABRs podem sumarizar rotas interareas entre areas. Os ASBRs podem sumarizar rotas externas que entram no dominio OSPF. Roteadores internos e DRs nao podem realizar sumarizacao."
  },
  {
    id: 69,
    question: "Um engenheiro de rede examinando a operacao EIGRP em um roteador percebe que uma rota em particular esta em estado ativo. O que o engenheiro pode determinar sobre esta rota?",
    options: [
      "Pacotes de dados serao encaminhados por esta rota.",
      "O algoritmo DUAL determinou um sucessor e um sucessor viavel para esta rota.",
      "Os processos EIGRP ainda estao calculando a distancia administrativa para esta rota.",
      "Mensagens de consulta EIGRP estao sendo enviadas a outros roteadores solicitando caminhos para esta rede."
    ],
    correct: [3],
    multiple: false,
    explanation: "No EIGRP, uma rota em estado 'ativo' significa que o DUAL perdeu a rota e esta consultando ativamente os vizinhos para um caminho alternativo (nenhum sucessor viavel existe). Mensagens de consulta sao enviadas a todos os vizinhos. Uma rota em estado 'passivo' e estavel e esta na tabela de roteamento."
  },
  {
    id: 70,
    question: "Um roteador precisa ser configurado para rotear dentro da Area 0 OSPF. Quais dois comandos sao necessarios? (Escolha dois.)",
    options: [
      "RouterA(config)# router ospf 0",
      "RouterA(config-router)# network 192.168.2.0 255.255.255.0 0",
      "RouterA(config-router)# network 192.168.2.0 0.0.0.255 area 0",
      "RouterA(config-router)# network 192.168.2.0 0.0.0.255 0",
      "RouterA(config)# router ospf 1"
    ],
    correct: [2, 4],
    multiple: true,
    explanation: "'router ospf 1' inicia o processo OSPF (o ID de processo pode ser qualquer numero de 1 a 65535, nao 0). 'network 192.168.2.0 0.0.0.255 area 0' usa a mascara curinga (nao a mascara de sub-rede) e especifica a area. O ID de processo e localmente significativo e nao precisa corresponder entre os roteadores."
  },
  {
    id: 71,
    question: "Qual afirmacao e verdadeira sobre os estados do Spanning Tree Protocol IEEE 802.1D?",
    options: [
      "As portas devem estar bloqueadas antes de poderem ser colocadas no estado desabilitado.",
      "As portas escutam e aprendem antes de entrar no estado de encaminhamento.",
      "As portas sao configuradas manualmente para estar no estado de encaminhamento.",
      "Leva 15 segundos para uma porta ir do bloqueio para o encaminhamento."
    ],
    correct: [1],
    multiple: false,
    explanation: "No STP 802.1D, as portas passam pelos estados: Bloqueio -> Escuta (15s) -> Aprendizado (15s) -> Encaminhamento. As portas escutam (processam BPDUs) e aprendem (populam a tabela MAC) antes de encaminhar o trafego. O tempo total do bloqueio ao encaminhamento e 30 segundos (2 x 15s de atraso de encaminhamento), nao 15 segundos."
  },
  {
    id: 72,
    question: "Qual e uma razao para usar o comando 'ip ospf priority' quando o OSPF esta em uso?",
    options: [
      "para influenciar o processo de eleicao DR/BDR",
      "para agilizar e acelerar o processo de convergencia",
      "para fornecer um caminho alternativo para conectividade durante a convergencia",
      "para ativar o processo de formacao de vizinhanca OSPF"
    ],
    correct: [0],
    multiple: false,
    explanation: "O comando 'ip ospf priority' (intervalo 0-255) influencia a eleicao DR/BDR. O roteador com maior prioridade se torna o DR. Uma prioridade de 0 impede que um roteador participe das eleicoes DR/BDR. A prioridade padrao e 1. Isso e usado para controlar qual roteador se torna DR em uma rede de acesso multiplo."
  },
  {
    id: 73,
    question: "Um administrador de rede esta configurando o balanceamento de carga EIGRP com o comando 'variance 3'. Qual e o resultado direto?",
    options: [
      "Quaisquer rotas de sucessor viavel para o mesmo destino com metrica igual ou inferior a 3 vezes a do sucessor serao instaladas na tabela de roteamento.",
      "Ate tres rotas de custo igual para o mesmo destino podem ser instaladas na tabela de roteamento.",
      "Independentemente de custo igual ou desigual, ate tres rotas para o mesmo destino podem ser instaladas.",
      "Ate tres rotas de custo desigual para o mesmo destino podem ser instaladas."
    ],
    correct: [0],
    multiple: false,
    explanation: "O comando 'variance' habilita o balanceamento de carga de custo desigual no EIGRP. 'variance 3' significa que qualquer rota de sucessor viavel com uma metrica de ate 3 vezes a metrica do sucessor sera incluida na tabela de roteamento. A rota deve ser um sucessor viavel (atender a condicao de viabilidade) para se qualificar."
  },
  {
    id: 74,
    question: "Quais sao dois metodos de balanceamento de carga na tecnologia EtherChannel? (Escolha duas.)",
    options: [
      "IP de origem para IP de destino",
      "MAC de origem para MAC de destino",
      "combinacao de MAC e IP de origem para MAC e IP de destino",
      "combinacao de porta e IP de origem para porta e IP de destino",
      "porta de origem para porta de destino"
    ],
    correct: [0, 1],
    multiple: true,
    explanation: "O EtherChannel suporta dois metodos principais de balanceamento de carga: MAC de origem para MAC de destino (Camada 2) e IP de origem para IP de destino (Camada 3). O metodo e configurado globalmente no switch. O trafego para um determinado par origem-destino sempre usa o mesmo link fisico."
  },
  {
    id: 75,
    question: "Qual declaracao descreve o numero de sistema autonomo usado na configuracao EIGRP em um roteador Cisco?",
    options: [
      "Carrega as informacoes geograficas da organizacao.",
      "Identifica o ISP que fornece a conexao para a rede.",
      "Funciona como um ID de processo na operacao do roteador.",
      "E um numero de sistema autonomo globalmente unico atribuido pela IANA."
    ],
    correct: [2],
    multiple: false,
    explanation: "O numero de sistema autonomo (SA) do EIGRP e localmente significativo e funciona como um ID de processo para diferenciar entre multiplas instancias EIGRP no mesmo roteador. NAO corresponde aos numeros de SA globalmente atribuidos do BGP pela IANA. Todos os roteadores no mesmo dominio EIGRP devem usar o mesmo numero de SA."
  },
  {
    id: 76,
    question: "Um administrador estava solucionando problemas em uma topologia de roteamento-no-palito (router-on-a-stick) e concluiu que o problema estava relacionado a configuracao de VLANs nas subinterfaces do roteador. Quais dois comandos podem ser usados para identificar o problema? (Escolha dois.)",
    options: [
      "show controllers",
      "show vlan",
      "show running-config",
      "show ip interface",
      "show ip protocols"
    ],
    correct: [2, 3],
    multiple: true,
    explanation: "Para solucionar problemas de configuracao de VLAN nas subinterfaces do roteador, 'show ip interface' exibe a configuracao da subinterface incluindo o encapsulamento (ID de VLAN 802.1Q), e 'show running-config' mostra a configuracao completa incluindo as configuracoes de subinterface. 'show vlan' e para o banco de dados VLAN do switch, nao para subinterfaces do roteador."
  },
  {
    id: 77,
    question: "Qual e uma distincao fundamental entre protocolos de roteamento classful e classless?",
    options: [
      "Protocolos de roteamento classful nao enviam informacoes de mascara de sub-rede em suas atualizacoes de roteamento.",
      "Protocolos de roteamento classful sao mais adequados para implementacao em redes descontíguas.",
      "Protocolos de roteamento classless nao sao escalaveis.",
      "Protocolos de roteamento classless nao permitem sumarizacao de rotas."
    ],
    correct: [0],
    multiple: false,
    explanation: "Protocolos de roteamento classful (RIPv1, IGRP) NAO incluem informacoes de mascara de sub-rede nas atualizacoes de roteamento, presumindo que todas as sub-redes da mesma rede principal usam a mesma mascara. Protocolos classless (RIPv2, EIGRP, OSPF) incluem informacoes de mascara de sub-rede, suportando VLSM e CIDR."
  },
  {
    id: 78,
    question: "Qual e uma caracteristica do EtherChannel?",
    options: [
      "O STP nao bloqueara pacotes EtherChannel redundantes entre dois switches.",
      "O STP trata todas as interfaces em um pacote como um unico link logico.",
      "A configuracao EtherChannel e aplicada a cada porta fisica individualmente.",
      "O EtherChannel usa portas fisicas atualizadas para fornecer uma conexao mais rapida."
    ],
    correct: [1],
    multiple: false,
    explanation: "O STP trata o pacote EtherChannel inteiro como um unico link logico, nao como multiplos links individuais. Isso significa que o STP nao bloqueara nenhuma das portas fisicas do pacote. A configuracao e aplicada a interface logica port channel (nao a cada porta fisica individualmente). O EtherChannel usa portas existentes sem upgrades de hardware."
  },
  {
    id: 79,
    question: "Qual comando pode ser usado por um administrador para exibir uma lista de interfaces habilitadas para OSPFv3?",
    options: [
      "show ipv6 protocols",
      "show ipv6 neighbor",
      "show ipv6 route ospf",
      "show ipv6 ospf"
    ],
    correct: [0],
    multiple: false,
    explanation: "'show ipv6 protocols' fornece informacoes-chave de configuracao OSPFv3, incluindo o ID de processo, ID de roteador e uma lista de interfaces habilitadas para roteamento OSPFv3. 'show ipv6 route ospf' mostra apenas rotas OSPF. 'show ipv6 ospf' mostra informacoes gerais do processo OSPF, mas nao a lista de interfaces."
  },
  {
    id: 80,
    question: "Que tipo de pacote EIGRP e usado pelos roteadores EIGRP para descobrir vizinhos em links diretamente conectados?",
    options: ["reconhecimento (acknowledgment)", "consulta (query)", "Hello", "atualizacao (update)"],
    correct: [2],
    multiple: false,
    explanation: "O EIGRP usa pacotes Hello para descoberta de vizinhos e para manter relacionamentos de vizinhanca. Os pacotes Hello sao enviados periodicamente como mensagens multicast (224.0.0.10) para o grupo multicast EIGRP. Quando dois roteadores EIGRP recebem os pacotes Hello um do outro, eles se tornam vizinhos."
  },
  {
    id: 81,
    question: "Como o ID de roteador para um roteador OSPFv3 e determinado?",
    options: [
      "o endereco IPv6 mais alto em uma interface ativa",
      "o ID EUI-64 mais alto em uma interface ativa",
      "o endereco IPv4 mais alto em uma interface ativa",
      "o endereco MAC mais baixo em uma interface ativa"
    ],
    correct: [2],
    multiple: false,
    explanation: "O OSPFv3 (para IPv6) ainda usa um ID de roteador de 32 bits no mesmo formato que o OSPFv2. A ordem de selecao e: 1) ID de roteador configurado explicitamente, 2) endereco IPv4 mais alto em uma interface loopback, 3) endereco IPv4 mais alto em qualquer interface ativa. Em redes somente IPv6, o ID de roteador deve ser configurado manualmente."
  },
  {
    id: 82,
    question: "Qual etapa pode ser adotada para garantir que um switch adicionado a rede nao sobrescreva os bancos de dados VLAN nos switches existentes?",
    options: [
      "Apagar a configuracao de inicializacao e reinicializar o switch.",
      "Redefinir o numero de revisao VTP do switch para 0.",
      "Excluir quaisquer VLANs configuradas e reinicializar o switch.",
      "Alterar o modo VTP para cliente."
    ],
    correct: [1],
    multiple: false,
    explanation: "Para adicionar com seguranca um switch a um dominio VTP existente, redefina seu numero de revisao para 0 primeiro. Isso pode ser feito alterando temporariamente o nome do dominio VTP ou alternando para o modo transparente e de volta. Um switch com numero de revisao maior sobrescreverá o banco de dados VLAN de todos os outros switches no dominio."
  },
  {
    id: 83,
    question: "Um administrador de rede esta planejando adicionar um novo switch. O que deve ser feito para garantir que o novo switch troque informacoes VTP com os outros switches?",
    options: [
      "Configurar o nome de dominio VTP e a senha corretos no novo switch.",
      "Associar todas as portas do novo switch a uma VLAN que nao seja a VLAN 1.",
      "Configurar todas as portas do novo switch no modo de acesso.",
      "Configurar as VLANs no novo switch."
    ],
    correct: [0],
    multiple: false,
    explanation: "Para troca de informacoes VTP, o novo switch deve ser configurado com o mesmo nome de dominio VTP e senha (se configurada) que os outros switches. Sem corresponder ao nome de dominio, o switch nao processara anuncios VTP de outros switches no dominio."
  },
  {
    id: 84,
    question: "Quando o comando 'show spanning-tree vlan 33' e emitido em um switch, tres portas sao mostradas no estado de encaminhamento. Em quais dois papeis de porta essas interfaces poderiam funcionar? (Escolha duas.)",
    options: ["bloqueada", "alternativa", "desabilitada", "Designada", "Raiz"],
    correct: [3, 4],
    multiple: true,
    explanation: "As portas no estado de encaminhamento podem ser portas Designadas (a melhor porta em um segmento de rede para alcançar a ponte raiz) ou portas Raiz (o melhor caminho para a ponte raiz em um switch nao-raiz). Portas alternativas e de backup estao no estado de descarte/bloqueio. Portas desabilitadas estao administrativamente desligadas."
  },
  {
    id: 85,
    question: "Quais dois parametros devem corresponder nas portas de dois switches para criar um EtherChannel PAgP entre os switches? (Escolha dois.)",
    options: ["endereco MAC", "informacoes de VLAN", "ID de porta", "Velocidade", "Modo PAgP"],
    correct: [1, 3],
    multiple: true,
    explanation: "Para que um EtherChannel seja formado, as portas em ambos os switches devem corresponder em velocidade, duplex e informacoes de VLAN (VLANs permitidas e VLAN nativa). O modo PAgP deve ser compativel (nao necessariamente igual). Enderecos MAC e IDs de porta nao precisam corresponder."
  },
  {
    id: 86,
    question: "Qual e o estado operacional final que se formara entre um DR OSPF e um DROTHER assim que os roteadores atingirem a convergencia?",
    options: ["estabelecido", "carregando (loading)", "bidirecional (two-way)", "Completo (Full)"],
    correct: [3],
    multiple: false,
    explanation: "Em redes de acesso multiplo OSPF, um DROTHER forma uma adjacencia Full com o DR e BDR apos sincronizar seus LSDBs. O estado Full significa que seus bancos de dados sao identicos. Dois DROTHERs apenas alcancam o estado 2-Way entre si. Estado Full = sincronizacao completa do LSDB."
  },
  {
    id: 87,
    question: "Qual comando e usado para exibir a largura de banda de uma interface em um roteador habilitado para EIGRP?",
    options: [
      "show ip interface brief",
      "show ip protocols",
      "show interfaces",
      "show ip route"
    ],
    correct: [2],
    multiple: false,
    explanation: "'show interfaces' exibe o valor de largura de banda configurado ou padrao para cada interface, junto com atraso, confiabilidade, carga e outras estatisticas usadas pelo EIGRP para o calculo de metricas. A largura de banda mostrada e o valor configurado (nao o throughput real), que o EIGRP usa em sua formula de metrica composta."
  },
  {
    id: 88,
    question: "Como as rotas EIGRP aprendidas externamente sao identificadas na tabela de roteamento?",
    options: ["EX", "*", "O1 E", "D"],
    correct: [0],
    multiple: false,
    explanation: "Na tabela de roteamento, as rotas EIGRP sao marcadas com 'D' (DUAL). Rotas EIGRP externas (redistribuidas de outros protocolos) sao marcadas como 'D EX'. A designacao 'EX' indica que a rota originou fora do sistema autonomo EIGRP e foi redistribuida para ele."
  },
  {
    id: 89,
    question: "O que o algoritmo SPF considera como o melhor caminho para uma rede?",
    options: [
      "O caminho que inclui o link de largura de banda mais rapida individual.",
      "O caminho com os menores atrasos.",
      "O caminho que inclui os links de largura de banda cumulativa mais rapidos.",
      "O caminho com o menor numero de saltos."
    ],
    correct: [2],
    multiple: false,
    explanation: "O algoritmo SPF do OSPF calcula o melhor caminho com base no menor custo acumulado. No OSPF, o custo e inversamente proporcional a largura de banda (custo = 10^8/largura_de_banda). O caminho com o menor custo total acumulado (largura de banda cumulativa mais rapida) e selecionado. Isso nao e necessariamente o menor numero de saltos."
  },
  {
    id: 90,
    question: "Qual protocolo o EIGRP usa para o transporte de pacotes EIGRP?",
    options: [
      "Transmission Control Protocol (TCP)",
      "User Datagram Protocol (UDP)",
      "Real-Time Transport Protocol",
      "Reliable Transport Protocol (Protocolo de Transporte Confiavel)"
    ],
    correct: [3],
    multiple: false,
    explanation: "O EIGRP usa seu proprio Protocolo de Transporte Confiavel (RTP) para entrega garantida e ordenada de pacotes EIGRP a todos os vizinhos. O RTP fornece entrega confiavel (para atualizacoes, consultas, respostas) e nao confiavel (para pacotes hello e ACK). O RTP e especifico do EIGRP e opera diretamente sobre IP."
  },
  {
    id: 91,
    question: "Qual e uma funcao dos pacotes hello OSPF?",
    options: [
      "garantir a sincronizacao do banco de dados entre roteadores",
      "descobrir vizinhos e construir adjacencias entre eles",
      "enviar registros de estado de link especificamente solicitados",
      "solicitar registros de estado de link especificos de roteadores vizinhos"
    ],
    correct: [1],
    multiple: false,
    explanation: "Os pacotes hello OSPF servem a tres funcoes: 1) Descobrir vizinhos OSPF e estabelecer adjacencias, 2) Anunciar parametros com que os vizinhos OSPF devem concordar (intervalos hello/dead, ID de area, flag de area stub, autenticacao), e 3) Eleger o DR e BDR em redes de acesso multiplo. A sincronizacao de banco de dados usa pacotes DBD."
  },
  {
    id: 92,
    question: "Um designer de rede esta considerando se deve implementar um bloco de switches. Qual e a principal vantagem de implantar um bloco de switches?",
    options: [
      "Um unico roteador de nucleo fornece todo o roteamento entre VLANs.",
      "A falha de um bloco de switches nao impactara todos os usuarios finais.",
      "Este e um recurso de seguranca disponivel em todos os novos switches Catalyst.",
      "Este e um software de aplicacao de rede que impede a falha de um unico dispositivo."
    ],
    correct: [1],
    multiple: false,
    explanation: "Um bloco de switches fornece isolamento de falhas. Se um bloco de switches falhar, apenas os usuarios conectados a esse bloco sao afetados. Outros blocos de switches e o restante da rede continuam operando normalmente. Isso limita o dominio de falha e melhora a disponibilidade geral da rede."
  },
  {
    id: 93,
    question: "Qual endereco e usado por um roteador EIGRP IPv6 como origem para mensagens hello?",
    options: [
      "o ID de roteador de 32 bits",
      "o endereco unicast global IPv6 configurado na interface",
      "o endereco multicast de todos os roteadores EIGRP",
      "o endereco IPv6 link-local da interface"
    ],
    correct: [3],
    multiple: false,
    explanation: "O EIGRP para IPv6 usa o endereco link-local (FE80::/10) da interface de saida do roteador como endereco de origem para todas as mensagens EIGRP, incluindo pacotes hello. Isso e consistente com como o OSPFv3 e outros protocolos IPv6 usam enderecos link-local para comunicacao com vizinhos."
  },
  {
    id: 94,
    question: "Qual descritor de tabela de roteamento e usado para identificar redes OSPF anunciadas por LSAs do tipo 1?",
    options: ["O", "O IA", "O E2", "O E1"],
    correct: [0],
    multiple: false,
    explanation: "'O' na tabela de roteamento indica uma rota OSPF intra-area (aprendida de LSAs Tipo 1 - Router LSAs). 'O IA' indica rotas interarea (de LSAs Tipo 3 Summary). 'O E1' indica rotas externas Tipo 1. 'O E2' indica rotas externas Tipo 2. LSAs do Tipo 1 sao Router LSAs inundados dentro de uma unica area."
  },
  {
    id: 95,
    question: "O que uma area OSPF contem?",
    options: [
      "roteadores cujas arvores SPF sao identicas",
      "roteadores que compartilham o mesmo ID de processo",
      "roteadores que tem as mesmas informacoes de estado de link em seus LSDBs",
      "roteadores que compartilham o mesmo ID de roteador"
    ],
    correct: [2],
    multiple: false,
    explanation: "Uma area OSPF contem roteadores que compartilham o mesmo Banco de Dados de Estado de Link (LSDB). Todos os roteadores dentro de uma area tem LSDBs identicos (embora cada um calcule sua propria arvore SPF independentemente). Os IDs de processo sao localmente significativos e nao precisam corresponder. Os IDs de roteador identificam exclusivamente cada roteador."
  },
  {
    id: 96,
    question: "Quais dois valores devem corresponder entre dois vizinhos EIGRP diretamente conectados para estabelecer e manter uma adjacencia? (Escolha dois.)",
    options: [
      "numero do sistema autonomo",
      "parametros de metrica (valores K)",
      "temporizadores hello",
      "ID do roteador",
      "ID de Area"
    ],
    correct: [0, 1],
    multiple: true,
    explanation: "Para adjacencia de vizinhanca EIGRP, o numero de SA deve ser igual em ambos os roteadores (devem estar no mesmo dominio EIGRP). Os valores K (parametros de metrica: largura de banda, atraso, confiabilidade, carga, MTU) tambem devem corresponder. Temporizadores hello, IDs de roteador e IDs de Area (usados pelo OSPF) nao precisam corresponder para o EIGRP."
  },
  {
    id: 97,
    question: "Quando um roteador executando EIGRP colocara uma rede de destino no estado ativo?",
    options: [
      "quando o dominio EIGRP convergiu",
      "quando ha trafego de saida para a rede de destino",
      "quando ha uma mensagem EIGRP do sucessor da rede de destino",
      "quando a conexao com o sucessor da rede de destino falha e nao ha sucessor viavel disponivel"
    ],
    correct: [3],
    multiple: false,
    explanation: "As rotas EIGRP estao normalmente no estado 'passivo' (estavel). Uma rota entra no estado 'ativo' quando o sucessor falha E nao existe sucessor viavel na tabela de topologia. No estado ativo, o roteador envia pacotes de Consulta a todos os vizinhos procurando um caminho alternativo. O estado passivo e o estado normal e saudavel."
  },
  {
    id: 98,
    question: "Qual e uma caracteristica do spanning tree?",
    options: [
      "Previne a propagacao de frames de broadcast de Camada 2.",
      "E habilitado por padrao nos switches Cisco.",
      "E usado para descobrir informacoes sobre um dispositivo Cisco adjacente.",
      "Tem um mecanismo TTL que funciona na Camada 2."
    ],
    correct: [1],
    multiple: false,
    explanation: "O STP e habilitado por padrao em todos os switches Cisco. Ele NAO previne frames de broadcast (eles ainda se propagam pela rede, apenas por um unico caminho sem loops). O STP NAO tem um mecanismo TTL (e por isso que o STP foi criado: a Camada 2 nao tem prevencao nativa de loops). O CDP descobre dispositivos Cisco adjacentes."
  },
  {
    id: 99,
    question: "Um administrador de rede insere o comando 'spanning-tree portfast bpduguard default'. Qual e o resultado?",
    options: [
      "Qualquer porta de switch sera desabilitada por erro se receber um BPDU.",
      "Quaisquer portas trunk poderao se conectar a rede imediatamente.",
      "Qualquer porta de switch configurada com PortFast sera desabilitada por erro se receber um BPDU.",
      "Qualquer porta de switch que receber um BPDU ignorara a mensagem BPDU."
    ],
    correct: [2],
    multiple: false,
    explanation: "O comando 'spanning-tree portfast bpduguard default' habilita o BPDU guard globalmente em todas as portas habilitadas para PortFast. Se um BPDU for recebido em uma porta PortFast (indicando que outro switch foi conectado), a porta e imediatamente colocada em estado de erro-desabilitado para proteger contra possiveis loops."
  },
  {
    id: 100,
    question: "Qual papel de porta e atribuido a porta do switch que tem o menor custo para alcançar a ponte raiz?",
    options: ["porta raiz", "porta nao designada", "porta designada", "porta desabilitada"],
    correct: [0],
    multiple: false,
    explanation: "A porta raiz em um switch nao-raiz e a porta com o menor custo de caminho acumulado para alcançar a ponte raiz. Cada switch nao-raiz tem exatamente uma porta raiz. A porta raiz sempre aponta na direcao da ponte raiz."
  },
  {
    id: 101,
    question: "Qual tecnologia e um padrao de protocolo aberto que permite que os switches agrupem automaticamente portas fisicas em um unico link logico?",
    options: ["Multilink PPP", "DTP", "LACP", "PAgP"],
    correct: [2],
    multiple: false,
    explanation: "O LACP (Link Aggregation Control Protocol) e definido pelo IEEE 802.3ad e e um padrao aberto que permite que os switches negociem e formem automaticamente pacotes EtherChannel. O PAgP e proprietario da Cisco. O DTP e proprietario da Cisco para negociacao de trunk. O Multilink PPP e para links WAN seriais."
  },
  {
    id: 102,
    question: "Quais dois modos de grupo de canais colocariam uma interface em estado de negociacao usando PAgP? (Escolha duas.)",
    options: ["desirable", "on", "active", "auto", "passive"],
    correct: [0, 3],
    multiple: true,
    explanation: "O PAgP usa os modos 'desirable' (inicia ativamente a negociacao) e 'auto' (aguarda passivamente a negociacao). Ambos colocam a interface em estado de negociacao (embora 'auto' aguarde o outro lado iniciar). O modo 'on' forca o EtherChannel sem negociacao. 'active' e 'passive' sao modos LACP, nao PAgP."
  },
  {
    id: 103,
    question: "Quais sao dois requisitos para poder configurar um EtherChannel entre dois switches? (Escolha dois.)",
    options: [
      "As interfaces envolvidas precisam ser contiguas no switch.",
      "Todas as interfaces precisam funcionar na mesma velocidade.",
      "Todas as interfaces precisam estar operando no mesmo modo duplex.",
      "Todas as interfaces precisam ser atribuidas a VLANs diferentes.",
      "Diferentes faixas permitidas de VLANs devem existir em cada extremidade."
    ],
    correct: [1, 2],
    multiple: true,
    explanation: "Para formacao do EtherChannel, todas as interfaces participantes devem operar na mesma velocidade e modo duplex. Elas tambem devem compartilhar a mesma configuracao de VLAN (mesma VLAN de acesso ou mesmas VLANs permitidas/nativas para trunks). As interfaces nao precisam ser fisicamente contiguas. Todas as interfaces sao atribuidas a mesma VLAN (nao a VLANs diferentes)."
  },
  {
    id: 104,
    question: "Quais sao os dois metodos usados por um NIC sem fio para descobrir um ponto de acesso (AP)? (Escolha dois.)",
    options: [
      "enviando uma solicitacao ARP",
      "entregando um frame de broadcast",
      "transmitindo uma solicitacao de sonda (probe request)",
      "iniciando um handshake de tres vias",
      "recebendo um frame de beacon de broadcast"
    ],
    correct: [2, 4],
    multiple: true,
    explanation: "Dispositivos sem fio descobrem APs de duas maneiras: Modo passivo: o NIC sem fio recebe frames de beacon de broadcast que o AP transmite periodicamente contendo SSID e capacidades. Modo ativo: o NIC sem fio transmite frames de solicitacao de sonda procurando SSIDs especificos, e os APs respondem com respostas de sonda."
  },
  {
    id: 105,
    question: "Em uma faculdade local, os alunos podem conectar-se a rede sem fio sem usar uma senha. Qual modo esta usando o ponto de acesso?",
    options: ["rede (network)", "aberto (open)", "passivo (passive)", "chave compartilhada (shared-key)"],
    correct: [1],
    multiple: false,
    explanation: "A autenticacao aberta (open) e um mecanismo de autenticacao nulo: qualquer dispositivo pode se conectar sem credenciais. E usada onde a seguranca nao e uma preocupacao ou onde outro mecanismo de seguranca (como um portal cativo) e usado. A chave compartilhada usa uma chave pre-compartilhada (WEP/WPA). O modo passivo e um modo de varredura, nao de autenticacao."
  },
  {
    id: 106,
    question: "Qual metodo de criptografia sem fio e o mais seguro?",
    options: ["WPA", "WEP", "WPA2 com TKIP", "WPA2 com AES"],
    correct: [3],
    multiple: false,
    explanation: "WPA2 com AES (Advanced Encryption Standard) e a criptografia sem fio mais forte. O AES usa chaves de 128, 192 ou 256 bits e e considerado inquebravel com a tecnologia atual. O WEP esta gravemente comprometido. O WPA com TKIP e mais forte que o WEP, mas mais fraco que o WPA2. O WPA2 com TKIP tambem e menos seguro que o WPA2 com AES."
  },
  {
    id: 107,
    question: "Quais dois comandos devem ser emitidos para forcar a autenticacao MD5 para todas as interfaces habilitadas para OSPF na area backbone? (Escolha dois.)",
    options: [
      "ip ospf message-digest-key 1 md5 1C34dE",
      "area 1 authentication message-digest",
      "username OSPF password 1C34dE",
      "enable password 1C34dE",
      "area 0 authentication message-digest"
    ],
    correct: [0, 4],
    multiple: true,
    explanation: "Dois comandos sao necessarios: 1) 'ip ospf message-digest-key 1 md5 1C34dE' (configurado em cada interface, define a chave) e 2) 'area 0 authentication message-digest' (habilita a autenticacao MD5 para a Area 0, a area backbone). 'area 1' configuraria a Area 1, nao o backbone. Comandos de nome de usuario/senha de habilitacao nao sao para autenticacao OSPF."
  },
  {
    id: 108,
    question: "Quais sao dois metodos para tornar o protocolo de roteamento OSPF mais seguro? (Escolha dois.)",
    options: [
      "Usar apenas OSPFv3.",
      "Usar autenticacao MD5.",
      "Usar o comando enable secret.",
      "Quando viavel, criar um tunel VPN entre cada adjacencia de vizinho OSPF.",
      "Usar o comando passive-interface em interfaces LAN conectadas apenas a dispositivos do usuario final."
    ],
    correct: [1, 4],
    multiple: true,
    explanation: "A seguranca OSPF e melhorada por: autenticacao MD5 (verifica que os pacotes OSPF vem de roteadores confiaveis, prevenindo que roteadores desonestos injetem informacoes de roteamento falsas), e usando 'passive-interface' em interfaces LAN de camada de acesso (impede que pacotes hello OSPF sejam enviados em interfaces sem vizinhos OSPF, reduzindo a superficie de ataque)."
  },
  {
    id: 109,
    question: "Quando um roteador OSPF se torna um ABR (Area Border Router)?",
    options: [
      "quando o roteador tem interfaces em diferentes areas",
      "quando o roteador e configurado como ABR pelo administrador de rede",
      "quando o roteador tem o maior ID de roteador",
      "quando o roteador tem uma prioridade OSPF de 0"
    ],
    correct: [0],
    multiple: false,
    explanation: "Um Roteador de Fronteira de Area (ABR) e automaticamente designado quando um roteador tem interfaces conectadas a duas ou mais areas OSPF diferentes. Nenhuma configuracao explicita de ABR e necessaria: o roteador se torna ABR em virtude das atribuicoes de area de sua interface. Em seguida, ele mantem LSDBs separados para cada area conectada."
  },
  {
    id: 110,
    question: "Qual tipo de LSA OSPF representa uma rota externa e e propagado em todo o dominio OSPF?",
    options: ["tipo 1", "tipo 2", "tipo 3", "tipo 4", "tipo 5"],
    correct: [4],
    multiple: false,
    explanation: "LSAs do Tipo 5 (LSAs Externas de SA) sao gerados pelos ASBRs para anunciar rotas aprendidas de fora do dominio OSPF (por exemplo, do BGP, EIGRP, rotas estaticas). Elas sao inundadas por todo o dominio OSPF (exceto areas stub). Os ABRs encaminham LSAs do Tipo 5 sem modificacao."
  },
  {
    id: 111,
    question: "Quando os pacotes de atualizacao EIGRP sao enviados?",
    options: [
      "somente quando necessario",
      "quando as rotas aprendidas expiram",
      "a cada 5 segundos via multicast",
      "a cada 30 segundos via broadcast"
    ],
    correct: [0],
    multiple: false,
    explanation: "O EIGRP e orientado a eventos, nao orientado a temporizadores. Ele envia pacotes de atualizacao somente quando ocorre uma mudanca de topologia (atualizacoes disparadas). As entradas de rota na tabela de roteamento EIGRP NAO expiram (sem temporizador hold-down para rotas). Isso e mais eficiente do que as atualizacoes periodicas usadas pelo RIP."
  },
  {
    id: 112,
    question: "Um administrador emite o comando 'router eigrp 100' em um roteador. Para que e usado o numero 100?",
    options: [
      "como o numero do sistema autonomo",
      "como o numero de vizinhos suportados por este roteador",
      "como o tempo que este roteador aguardara para receber pacotes hello de um vizinho",
      "como a largura de banda maxima da interface mais rapida no roteador"
    ],
    correct: [0],
    multiple: false,
    explanation: "Em 'router eigrp 100', o numero 100 e o numero do sistema autonomo (SA) que tambem funciona como um ID de processo. Multiplos processos EIGRP podem ser executados simultaneamente com diferentes numeros de SA, permitindo ao roteador participar em multiplos dominios EIGRP. Todos os roteadores no mesmo dominio EIGRP devem usar o mesmo numero de SA."
  },
  {
    id: 113,
    question: "Quais dois parametros o EIGRP usa por padrao para calcular o melhor caminho? (Escolha dois.)",
    options: ["atraso (delay)", "MTU", "confiabilidade (reliability)", "carga de transmissao e recepcao", "largura de banda (bandwidth)"],
    correct: [0, 4],
    multiple: true,
    explanation: "O EIGRP usa uma metrica composta. Por padrao, apenas a largura de banda (o link mais lento no caminho) e o atraso (a soma de todos os atrasos de interface) sao usados no calculo da metrica (K1=1, K2=0, K3=1, K4=0, K5=0). Confiabilidade e carga podem ser incluidas modificando os valores K, mas isso nao e recomendado. O MTU e transportado nas atualizacoes, mas nao e usado como metrica."
  },
  {
    id: 114,
    question: "Quando um roteador Cisco e configurado com comutacao rapida (fast-switching), como os pacotes sao distribuidos por caminhos de custo igual?",
    options: [
      "por pacote",
      "por interface",
      "por carga do caminho",
      "por destino"
    ],
    correct: [3],
    multiple: false,
    explanation: "Com a comutacao rapida da Cisco (mecanismo de cache), o balanceamento de carga ocorre por destino: todos os pacotes para o mesmo destino usam o mesmo caminho (armazenado em cache). A comutacao de processo usa balanceamento de carga por pacote. O CEF (Cisco Express Forwarding) usa por destino por padrao."
  },
  {
    id: 115,
    question: "Quais sao dois motivos para implementar interfaces passivas na configuracao EIGRP? (Escolha dois.)",
    options: [
      "para fornecer maior seguranca de rede",
      "para desligar interfaces nao utilizadas",
      "para excluir interfaces do balanceamento de carga",
      "para mitigar ataques provenientes das interfaces",
      "para evitar trafego de atualizacao desnecessario"
    ],
    correct: [0, 4],
    multiple: true,
    explanation: "Interfaces passivas no EIGRP: 1) Suprimem trafego de atualizacao desnecessario em interfaces LAN onde nao existem vizinhos EIGRP (como portas de camada de acesso), e 2) Melhoram a seguranca impedindo que dispositivos desonestos estabelecam relacionamentos de vizinhanca EIGRP e injetem informacoes de roteamento falsas."
  },
  {
    id: 116,
    question: "Que tipo de rota OSPF IPv4 e indicado por um descritor de entrada na tabela de rotas de 'O E1'?",
    options: [
      "uma rota intra-area anunciada pelo DR",
      "uma rota de resumo anunciada por um ABR",
      "uma rota diretamente conectada associada a uma interface Ethernet",
      "uma rota externa anunciada por um ASBR"
    ],
    correct: [3],
    multiple: false,
    explanation: "O E1 indica uma rota externa OSPF do Tipo 1. 'O' = OSPF, 'E1' = externo tipo 1. Essas rotas sao originadas por um ASBR de uma fonte nao-OSPF. As rotas externas Tipo 1 adicionam o custo OSPF interno ao custo externo conforme a rota se propaga. O IA = interarea (do ABR), O = intra-area."
  },
  {
    id: 117,
    question: "Qual afirmacao e verdadeira sobre os papeis de porta do Rapid Spanning Tree Protocol 802.1w?",
    options: [
      "As portas sao configuradas manualmente para estar no papel designado.",
      "Aprimoramentos proprietarios da Cisco para o 802.1D legado, como UplinkFast e BackboneFast, sao compativeis com RSTP.",
      "Uma porta alternativa ou de backup pode mudar imediatamente para o estado de encaminhamento sem esperar a convergencia da rede.",
      "Leva 15 segundos para uma porta de borda ir do bloqueio para o encaminhamento."
    ],
    correct: [2],
    multiple: false,
    explanation: "O RSTP permite que portas alternativas e de backup facam a transicao imediata para o estado de encaminhamento se o caminho ativo falhar, por meio de um processo de negociacao rapida com os vizinhos. Isso elimina a espera de 30 segundos do 802.1D. UplinkFast/BackboneFast da Cisco sao tornados obsoletos pelo RSTP."
  },
  {
    id: 118,
    question: "Qual acao deve ser tomada ao planejar a redundancia em um design de rede hierarquica?",
    options: [
      "substituir imediatamente um modulo, servico ou dispositivo nao funcional em uma rede",
      "comprar continuamente equipamentos de backup para a rede",
      "implementar STP portfast entre os switches na rede",
      "adicionar caminhos fisicos alternativos para que os dados percorram a rede"
    ],
    correct: [3],
    multiple: false,
    explanation: "O principal metodo de implementar redundancia de rede e a redundancia de caminho: instalar caminhos fisicos alternativos para que os dados percorram a rede. Se um caminho falhar, o trafego e automaticamente redirecionado pelo caminho alternativo. Os caminhos redundantes sao gerenciados por protocolos como STP (Camada 2) e OSPF/EIGRP (Camada 3)."
  },
  {
    id: 119,
    question: "Quais sao duas desvantagens de desativar o spanning tree e ter multiplos caminhos pela rede de switch de Camada 2? (Escolha duas.)",
    options: [
      "Frames de broadcast sao transmitidos indefinidamente.",
      "A seguranca de porta desliga todas as portas a que os dispositivos estao conectados.",
      "O switch age como um hub.",
      "A tabela de enderecos MAC se torna instavel.",
      "A seguranca de porta se torna instavel."
    ],
    correct: [0, 3],
    multiple: true,
    explanation: "Sem o STP, os loops de Camada 2 causam: 1) Tempestades de broadcast: broadcasts sao encaminhados por todas as portas indefinidamente, pois nao ha TTL na Camada 2, consumindo toda a largura de banda. 2) Instabilidade na tabela MAC: os switches recebem frames da mesma fonte MAC em multiplas portas, atualizando constantemente a tabela MAC e causando encaminhamento incorreto."
  },
  {
    id: 120,
    question: "Um engenheiro de rede esta configurando uma LAN com um primeiro salto redundante para fazer melhor uso dos recursos de rede disponiveis. Qual protocolo o engenheiro deve implementar?",
    options: ["FHRP", "GLBP", "HSRP", "VRRP"],
    correct: [1],
    multiple: false,
    explanation: "O GLBP (Gateway Load Balancing Protocol) e o unico FHRP que fornece redundancia E balanceamento de carga. Multiplos roteadores encaminham ativamente o trafego simultaneamente (cada um recebendo um MAC virtual diferente). HSRP e VRRP tem apenas um gateway ativo por vez. FHRP e uma categoria, nao um protocolo especifico."
  },
  {
    id: 121,
    question: "Qual metodo de autenticacao sem fio e dependente de um servidor de autenticacao RADIUS?",
    options: ["WEP", "WPA Pessoal", "WPA2 Pessoal", "WPA2 Empresarial (Enterprise)"],
    correct: [3],
    multiple: false,
    explanation: "O WPA2 Enterprise usa IEEE 802.1X com um servidor RADIUS para autenticacao, fornecendo maior seguranca por meio de credenciais individuais do usuario. O WPA2 Personal usa uma chave pre-compartilhada (PSK). O WEP usa criptografia RC4 e esta gravemente comprometido. O WPA2 Enterprise e recomendado para ambientes corporativos que exigem responsabilidade individual."
  },
  {
    id: 122,
    question: "Qual tecnica de modulacao sem fio usada pelos padroes WLAN 802.11 pode implementar MIMO?",
    options: ["BSS", "DSSS", "FHSS", "OFDM"],
    correct: [3],
    multiple: false,
    explanation: "O OFDM (Orthogonal Frequency Division Multiplexing) e a tecnica de modulacao usada pelo 802.11a/g/n/ac/ax. O OFDM suporta tecnologia MIMO (Multiple Input Multiple Output) dividindo os dados em multiplas sub-portadoras e multiplas antenas simultaneamente. DSSS e FHSS sao tecnicas mais antigas do 802.11b."
  },
  {
    id: 123,
    question: "Para solucionar problemas de rotas EIGRP ausentes, quais tres tipos de informacoes podem ser coletadas usando o comando 'show ip protocols'? (Escolha tres.)",
    options: [
      "quaisquer interfaces habilitadas para autenticacao EIGRP",
      "quaisquer interfaces no roteador configuradas como passivas",
      "os enderecos IP configurados em roteadores adjacentes",
      "quaisquer ACLs que afetam o processo de roteamento EIGRP",
      "redes nao anunciadas pelo protocolo de roteamento EIGRP",
      "a interface local usada para estabelecer adjacencia com vizinhos EIGRP"
    ],
    correct: [1, 3, 4],
    multiple: true,
    explanation: "'show ip protocols' para EIGRP revela: interfaces passivas (interfaces que nao enviam hellos EIGRP), se a sumarizacao automatica esta ativa, se quaisquer ACLs estao filtrando atualizacoes EIGRP e redes NAO sendo anunciadas. Nao mostra configuracao de autenticacao nem enderecos IP de roteadores adjacentes."
  },
  {
    id: 124,
    question: "Qual funcao e fornecida pelo EtherChannel?",
    options: [
      "distribuir trafego por multiplos links WAN fisicos",
      "dividir a largura de banda de um unico link em slots de tempo separados",
      "habilitar trafego de multiplas VLANs para viajar por um unico link de Camada 2",
      "criar um unico link logico usando multiplos links fisicos entre dois switches LAN"
    ],
    correct: [3],
    multiple: false,
    explanation: "O EtherChannel cria um unico link logico de alta largura de banda agregando multiplos links Ethernet fisicos entre dois switches. O link logico tem a largura de banda combinada de todos os links fisicos. O STP o ve como um unico link (sem portas bloqueadas), e a configuracao e aplicada no nivel da interface logica port-channel."
  },
  {
    id: 125,
    question: "Apos implementar uma rede IPv6, o administrador percebe que o processo OSPFv3 nao esta iniciando nos roteadores. Qual pode ser o problema?",
    options: [
      "Nenhum ID de roteador esta configurado nos roteadores.",
      "A autenticacao nao foi implementada entre os roteadores.",
      "Os roteadores nao foram configurados com o comando network.",
      "Os roteadores estao configurados com a prioridade padrao."
    ],
    correct: [0],
    multiple: false,
    explanation: "O OSPFv3 requer um ID de roteador de 32 bits (mesmo formato que o OSPFv2). Em um ambiente somente IPv6 sem enderecos IPv4 configurados, nao ha endereco IP para selecao automatica do ID de roteador. O ID de roteador deve ser configurado manualmente com o comando 'router-id'; caso contrario, o OSPFv3 falha ao iniciar. O comando 'network' nao e usado no OSPFv3."
  },
  {
    id: 126,
    question: "Qual declaracao descreve o comportamento de balanceamento de carga do EIGRP?",
    options: [
      "EIGRP para IPv6 suporta balanceamento de carga de custo desigual, mas EIGRP para IPv4 nao.",
      "EIGRP para IPv4 suporta balanceamento de carga de custo desigual, mas EIGRP para IPv6 nao.",
      "Nem o EIGRP para IPv4 nem o EIGRP para IPv6 suportam balanceamento de carga de custo desigual.",
      "Tanto o EIGRP para IPv4 quanto o EIGRP para IPv6 suportam balanceamento de carga de custo desigual."
    ],
    correct: [3],
    multiple: false,
    explanation: "Tanto o EIGRP para IPv4 quanto o EIGRP para IPv6 suportam balanceamento de carga de custo desigual usando o comando 'variance'. Este e um recurso unico do EIGRP nao disponivel no OSPF. O multiplicador de variancia especifica quanto maior a metrica dos caminhos alternativos pode ser em comparacao com a metrica do sucessor."
  },
  {
    id: 127,
    question: "Qual e um requisito para configurar um EtherChannel trunk entre dois switches?",
    options: [
      "As interfaces participantes devem estar no mesmo modulo em um switch.",
      "As interfaces participantes devem ser fisicamente contiguas em um switch.",
      "As interfaces participantes devem ser atribuidas ao mesmo numero de VLAN em ambos os switches.",
      "A faixa permitida de VLANs deve ser a mesma em ambos os switches."
    ],
    correct: [3],
    multiple: false,
    explanation: "Para um EtherChannel trunk, a faixa permitida de VLANs deve corresponder em todas as interfaces participantes em ambos os switches. Se as faixas de VLAN diferirem, o EtherChannel nao pode ser formado (as portas serao colocadas em estado de erro-desabilitado). As interfaces nao precisam ser fisicamente contiguas ou estar no mesmo modulo."
  },
  {
    id: 128,
    question: "Enquanto participava de uma conferencia, um palestrante convidado tenta se conectar a rede, mas o laptop nao exibe redes sem fio disponiveis. O ponto de acesso provavelmente esta operando em qual modo?",
    options: ["passivo", "misto", "aberto", "ativo"],
    correct: [3],
    multiple: false,
    explanation: "Quando um AP opera no modo 'ativo' para transmissao de SSID, ele NAO transmite frames de beacon. O SSID esta oculto. Os clientes devem conhecer o SSID e fazer uma sonda ativamente por ele. No modo 'passivo', o AP transmite frames de beacon com o SSID, permitindo que os clientes descubram a rede automaticamente."
  },
  {
    id: 129,
    question: "Qual e um recurso do protocolo de roteamento OSPF?",
    options: [
      "A autenticacao OSPF e configurada da mesma forma em redes IPv4 e IPv6.",
      "O algoritmo SPF escolhe o melhor caminho com base em atualizacoes de 30 segundos.",
      "Os roteadores podem ser agrupados em sistemas autonomos para suportar um sistema hierarquico.",
      "Escala bem em redes pequenas e grandes."
    ],
    correct: [3],
    multiple: false,
    explanation: "O OSPF foi projetado para escalar bem por meio de sua estrutura hierarquica de areas, suportando tanto implantacoes de area unica pequenas quanto redes de multiplas areas grandes com milhares de roteadores. O OSPF usa atualizacoes disparadas (nao periodicas de 30 segundos). No IPv4, OSPF usa autenticacao MD5; no IPv6, OSPFv3 usa IPsec (abordagem diferente). O OSPF usa areas, nao sistemas autonomos."
  },
  {
    id: 130,
    question: "O que deve ser instalado em um roteador Cisco como pre-requisito para instalar as licencas de Dados, Seguranca e Comunicacoes Unificadas no IOS 15?",
    options: [
      "a licenca IP Base",
      "o Cisco License Manager",
      "o pacote Enterprise Services",
      "a licenca Enterprise Base"
    ],
    correct: [0],
    multiple: false,
    explanation: "No Cisco IOS 15, a licenca IP Base e a base que deve ser instalada primeiro. O pacote de tecnologia IP Base fornece capacidades de roteamento IP fundamentais. Dados, Seguranca e Comunicacoes Unificadas sao pacotes de tecnologia adicionais que requerem IP Base como pre-requisito."
  }
];
