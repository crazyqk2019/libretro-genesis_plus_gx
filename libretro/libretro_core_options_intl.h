#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */

/* RETRO_LANGUAGE_SPANISH */

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

struct retro_core_option_definition option_defs_pt_br[] = {
   {
      "genesis_plus_gx_system_hw",
      "Hardware do sistema",
      "Executa o conteúdo carregado com um console emulado específico. 'Automático' selecionará o sistema mais apropriado para o jogo atual.",
      {
         { "auto",                 NULL },
         { "sg-1000",              "SG-1000"            },
         { "sg-1000 II",           "SG-1000 II"         },
         { "mark-III",             "Mark III"           },
         { "master system",        "Master System"      },
         { "master system II",     "Master System II"   },
         { "game gear",            "Game Gear"          },
         { "mega drive / genesis", "Mega Drive" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_region_detect",
      "Região do sistema",
      "Especifica de que região o sistema é. Para consoles que não sejam o Game Gear, 'PAL' é de 50hz enquanto 'NTSC' é de 60hz. s jogos podem ser executados mais rapidamente ou mais lentamente do que o normal se a região incorreta estiver selecionada.",
      {
         { "auto",    NULL },
         { "ntsc-u",  "NTSC-U" },
         { "pal",     "PAL"    },
         { "ntsc-j",  "NTSC-J" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_force_dtack",
      "Bloqueios do sistema",
      "Emula os bloqueios do sistema que ocorrem no hardware real ao executar acesso ilegal a endereços. Isso só deve ser desativado ao reproduzir certas demos e homebrews que dependem de comportamento ilegal para a operação correta.",
      {
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_bios",
      "ROM de inicialização do sistema",
      "Usa a BIOS/bootloader oficial para o hardware emulado, se estiver presente no diretório de sistema do RetroArch. Exibe a sequência/animação da inicialização específica do console e executa o conteúdo carregado.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_bram",
      "Sistema BRAM do CD",
      "Ao executar o conteúdo de CD da Sega, especifica se um único arquivo salvo será salvo entre todos os jogos de uma região específica (Por-BIOS) ou se será criado um arquivo salvo separado para cada jogo (Por-Jogo). Observe que o CD da Sega possui armazenamento interno limitado, suficiente apenas para alguns títulos. Para evitar ficar sem espaço, a configuração 'Por jogo' é recomendada.",
      {
         { "per bios", "Por-BIOS" },
         { "per game", "Por-Jogo" },
         { NULL, NULL },
      },
      "per bios"
   },
   {
      "genesis_plus_gx_addr_error",
      "Erro de endereçamento do 68K",
      "A CPU do Mega Drive (Motorola 68000) produz um erro de endereçamento (falha) ao tentar executar o acesso desalinhado à memória. A ativação do 'Erro de endereçamento do 68K' simula esse comportamento. Ele deve ser desativado apenas durante a execução de hacks de ROMs, pois geralmente são desenvolvidos usando emuladores menos precisos e podem contar com acesso inválido à RAM para a operação correta.",
      {
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_lock_on",
      "Cartucho Lock-On",
      "A tecnologia Lock-On é um recurso do Mega Drive que permite que um jogo mais antigo se conecte à porta de passagem de um cartucho especial para uma jogabilidade estendida ou alterada. Esta opção especifica qual tipo de cartucho especial 'lock-on' a ser emulado. Um arquivo do BIOS correspondente deve estar presente no diretório do sistema do RetroArch.",
      {
         { "disabled",            NULL },
         { "game genie",          "Game Genie" },
         { "action replay (pro)", "Action Replay (Pro)" },
         { "sonic & knuckles",    "Sonic & Knuckles" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_ym2413",
      "Som FM do Master System (YM2413)",
      "Ativa a emulação da unidade de som FM usada por certos jogos do Master System para obter uma saída de áudio aprimorada.",
      {
         { "auto",     NULL },
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_ym2612",
      "Som FM do Mega Drive",
#ifdef HAVE_YM3438_CORE
      "Seleciona o método usado para emular o sintetizador FM (gerador de som principal) do Mega Drive. As opções 'MAME' são rápidas e executam a toda velocidade na maioria dos sistemas. As opções 'Nuked' têm precisão de ciclo, qualidade muito alta e requisitos substanciais de CPU. O chip 'YM2612' é usado pelo Mega Drive Modelo 1 original. O 'YM3438' é usado em revisões posteriores do Mega Drive.",
#else
      "Seleciona o método usado para emular o sintetizador de FM (gerador de som principal) do Mega Drive. O chip 'YM2612' é usado pelo Mega Drive Modelo 1 original. O 'YM3438' é usado em revisões posteriores do Mega Drive.",
#endif
      {
         { "mame (ym2612)",          "MAME (YM2612)" },
         { "mame (asic ym3438)",     "MAME (ASIC YM3438)" },
         { "mame (enhanced ym3438)", "MAME (YM3438 aprimorado)" },
#ifdef HAVE_YM3438_CORE
         { "nuked (ym2612)",         "Nuked (YM2612)" },
         { "nuked (ym3438)",         "Nuked (YM3438)" },
#endif
         { NULL, NULL },
      },
      "mame (ym2612)"
   },
   {
      "genesis_plus_gx_sound_output",
      "Saída de som",
      "Selecione reprodução de som estéreo ou mono.",
      {
         { "stereo", "Estéreo" },
         { "mono",   "Mono" },
         { NULL, NULL },
      },
      "stereo"
   },
   {
      "genesis_plus_gx_psg_preamp",
      "Nível de pré-amplificação do PSG",
      "Define o nível de pré-amplificação do áudio do Gerador de Som Programável (PSG) de 4 canais SN76496 emulado encontrado no Master System, Game Gear e Mega Drive.",
      {
         { NULL, NULL },
      },
      "150"
   },
   {
      "genesis_plus_gx_fm_preamp",
      "Nível de pré-amplificação do FM",
      "Define o nível de pré-amplificação de áudio da Unidade de Som FM emulada do Master System.",
      {
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_filter",
      "Filtro de áudio",
      "Ativa um filtro de áudio passa-baixo para simular melhor o som característico de um Mega Drive Modelo 1.",
      {
         { "disabled", NULL },
         { "low-pass", "Passa-baixo" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lowpass_range",
      "Filtro passa-baixo %",
      "Especifica a frequência de corte do filtro de áudio passa-baixo. Um valor mais alto aumenta a 'força' percebida do filtro, uma vez que uma faixa mais ampla do espectro de alta frequência é atenuada.",
      {
         { NULL, NULL },
      },
      "60"
   },
#ifdef HAVE_EQ
   {
      "genesis_plus_gx_audio_eq_low",
      "EQ baixa",
      "Ajuste a banda de alcance baixo do equalizador de áudio interno.",
      {
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_mid",
      "EQ média",
      "Ajuste a banda de alcance média do equalizador de áudio interno.",
      {
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_high",
      "EQ alta",
      "Ajuste a banda de alcance alta do equalizador de áudio interno.",
      {
         { NULL, NULL },
      },
      "100"
   },
#endif
   {
      "genesis_plus_gx_blargg_ntsc_filter",
      "Filtro Blargg NTSC",
      "Aplica um filtro de vídeo para imitar vários sinais de TV NTSC.",
      {
         { "disabled",   NULL },
         { "monochrome", "Monocromático" },
         { "composite",  "Composto" },
         { "svideo",     "S-Video" },
         { "rgb",        "RGB" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lcd_filter",
      "Filtro fantasma LCD",
      "Aplica um filtro de imagem fantasma para imitar as características de exibição dos painéis de LCD do Game Gear e do 'Genesis Nomad'.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_overscan",
      "Bordas",
      "Ative esta opção para exibir as regiões de overscan na parte superior/inferior e/ou esquerda/direita da tela. Normalmente, seriam ocultas pelo painel ao redor da borda de uma televisão de definição padrão.",
      {
         { "disabled",   NULL },
         { "top/bottom", "Superior/inferior" },
         { "left/right", "Esquerda/direita" },
         { "full",       "Completa" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gg_extra",
      "Tela estendida do Game Gear",
      "Força os títulos do Game Gear a serem executados no modo 'SMS', com uma resolução aumentada de 256x192. Pode mostrar conteúdo adicional, mas geralmente exibe uma borda de dados corrompidos/indesejados de imagem.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_aspect_ratio",
      "Proporção de aspecto fornecida pelo núcleo",
      "Escolhe a proporção preferida do conteúdo. Isso se aplicará somente quando a proporção do RetroArch estiver configurada como 'Core provided' nas configurações de vídeo.",
      {
         { "auto",     NULL },
         { "NTSC PAR", NULL },
         { "PAL PAR",  NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_render",
      "Saída entrelaçada modo 2",
      "O Modo entrelaçado 2 permite que o Mega Drive produza uma imagem de 320x448 de altura dupla (alta resolução) desenhando linhas de varredura alternativas em cada quadro (isso é usado pelos modos multijogador do 'Sonic the Hedgehog 2' e 'Combat Cars'). O 'Campo duplo' imita o hardware original, produzindo uma imagem nítida com artefatos trêmulos/entrelaçados. O 'Campo único' é um filtro de desentrelaçamento, que estabiliza a imagem, mas causa desfoque suave.",
      {
         { "single field", "Campo único" },
         { "double field", "Campo duplo" },
         { NULL, NULL },
      },
      "single field"
   },
   {
      "genesis_plus_gx_gun_cursor",
      "Mostrar mira da pistola",
      "Exibe a mira da pistola de luz ao usar os tipos de dispositivo de entrada 'MD Menacer', 'MD Justifiers' e 'MS Light Phaser'.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gun_input",
      "Saída da Pistola de luz",
      "Usa uma entrada 'Pistola de luz' ou 'Toque na tela' controlada por mouse.",
      {
         { "lightgun",    "Pistola de luz" },
         { "touchscreen", "Toque na tela" },
         { NULL, NULL },
      },
      "lightgun"
   },
   {
      "genesis_plus_gx_invert_mouse",
      "Inverter eixo Y do mouse",
      "Inverte o eixo Y do tipo de dispositivo de entrada 'MD Mouse'.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
#ifdef HAVE_OVERCLOCK
   {
      "genesis_plus_gx_overclock",
      "Velocidade da CPU",
      "Faz um overclock da CPU emulada. Pode reduzir a desaceleração, mas pode causar falhas.",
      {
         { NULL, NULL },
      },
      "100%"
   },
#endif
   {
      "genesis_plus_gx_no_sprite_limit",
      "Remover limite de sprite por linha",
      "Remove o limite de sprite por varredura do hardware, 8 (Master System) ou 20 (Mega Drive). Isso reduz a tremulação (flickering), mas pode causar falhas visuais, pois alguns jogos exploram o limite de hardware para gerar efeitos especiais.",
      {
         { NULL, NULL },
      },
      "disabled"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */

struct retro_core_option_definition option_defs_chs[] = {
   {
      "genesis_plus_gx_system_hw",
      "系统硬件",
      "以指定的模拟硬件运行载入的游戏，'自动'会根据当前游戏选择最合适的系统。",
      {
         { "auto",                 "自动"               },
         { "sg-1000",              "SG-1000"            },
         { "sg-1000 II",           "SG-1000 II"         },
         { "mark-III",             "Mark III"           },
         { "master system",        "Master System"      },
         { "master system II",     "Master System II"   },
         { "game gear",            "Game Gear"          },
         { "mega drive / genesis", "Mega Drive/Genesis" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_region_detect",
      "系统制式",
      "指定系统区域制式。除Game Gear外，'PAL'是50hz而'NTSC'是60hz。\n"
      "如果选择了不正确的制式，游戏可能比正常运行速度偏快或者偏慢。",
      {
         { "auto",    "自动"   },
         { "ntsc-u",  "NTSC-U" },
         { "pal",     "PAL"    },
         { "ntsc-j",  "NTSC-J" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_force_dtack",
      "系统锁定",
      "模拟真实硬件上执行非法地址访问时发生的系统锁定。\n"
      "此设置应该只在运行特定演示或者自制游戏时关闭，这些游戏可能依赖非法行为来完成操作。",
      {
         { "enabled",  "启用" },
         { "disabled", "禁用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_bios",
      "系统启动ROM",
      "使用官方BIOS/启动器加载器，如果在RetroArch系统目录中存在的话。\n"
      "显示机种特定启动动画，然后运行载入的游戏。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_bram",
      "CD系统BRAM",
      "运行Sega CD游戏时，指定是在每个区域的游戏（按区域）中共享存档文件，还是为每个游戏（按游戏）单独保存存档。 \n"
      "注意：Sega CD内部存储容量有限，只够保存几个游戏。为了避免存储空间不够用，建议选择‘按游戏’。",
      {
         { "per bios", "按区域" },
         { "per game", "按游戏" },
         { NULL, NULL },
      },
      "per bios"
   },
   {
      "genesis_plus_gx_addr_error",
      "68K寻址错误",
      "MD的CPU（摩托罗拉68000）在执行未对齐内存访问时会产生一个寻址错误（宕机）。\n"
      "启用此设置模拟该行为。此设置应该只在运行修改版ROM时关闭，\n"
      "因为这些ROM通常是在不精确的模拟器上修改的，可能依赖于无效的内存访问才能正确运行。",
      {
         { "enabled",  "启用" },
         { "disabled", "禁用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_lock_on",
      "卡带锁定",
      "锁定技术是MD的一项功能，该功能允许老游戏连接到特殊卡带的传输端口上，进行扩展游戏或者实现附加功能。\n"
      "此设置指定模拟何种类型的‘锁定’功能。RetroArch系统目录中必须有相对应的BIOS文件。",
      {
         { "disabled",            "禁用" },
         { "game genie",          "Game Genie" },
         { "action replay (pro)", "Action Replay (Pro)" },
         { "sonic & knuckles",    "Sonic & Knuckles" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_ym2413",
      "Master System FM音源（YM2413）",
      "启用Sega Mark III/Master System FM声音单元的模拟，以增强某些游戏的声音输出。",
      {
         { "auto",     "自动" },
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_ym2612",
      "Mega Drive / Genesis FM音源",
#ifdef HAVE_YM3438_CORE
      "选择模拟MD/Genesis FM合成器（主声音发生器）的方式。\n"
      "'MAME'方式较快，在绝大多数系统上都可以全速运行。\n"
      "'Nuked'方式较精确，声音质量更高，但是需要更高的CPU性能。\n"
      "'YM2612'芯片由早期MD1型机使用，'YM3438'由后期MD机型使用。",
#else
      "选择模拟MD/Genesis FM合成器（主声音发生器）的方式。\n"
      "'YM2612'芯片由早期MD1型机使用，'YM3438'由后期MD机型使用。",
#endif
      {
         { "mame (ym2612)",          "MAME (YM2612)" },
         { "mame (asic ym3438)",     "MAME (ASIC YM3438)" },
         { "mame (enhanced ym3438)", "MAME (Enhanced YM3438)" },
#ifdef HAVE_YM3438_CORE
         { "nuked (ym2612)",         "Nuked (YM2612)" },
         { "nuked (ym3438)",         "Nuked (YM3438)" },
#endif
         { NULL, NULL },
      },
      "mame (ym2612)"
   },
   {
      "genesis_plus_gx_sound_output",
      "输出声道",
      "选择立体声或单声道声音输出。",
      {
         { "stereo", "立体声" },
         { "mono",   "单声道" },
         { NULL, NULL },
      },
      "stereo"
   },
   {
      "genesis_plus_gx_psg_preamp",
      "PSG预放大级别",
      "设置的SN76496四通道可编程声音发生器的声音预放大级别，\n"
      "此芯片用于Master System、Game Gear和MD/Genesis。",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { "105", NULL },
         { "110", NULL },
         { "115", NULL },
         { "120", NULL },
         { "125", NULL },
         { "130", NULL },
         { "135", NULL },
         { "140", NULL },
         { "145", NULL },
         { "150", NULL },
         { "155", NULL },
         { "160", NULL },
         { "165", NULL },
         { "170", NULL },
         { "175", NULL },
         { "180", NULL },
         { "185", NULL },
         { "190", NULL },
         { "195", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "150"
   },
   {
      "genesis_plus_gx_fm_preamp",
      "FM预放大级别",
      "设置FM音频芯片的预放大级别，此芯片用于Sega Mark III/Master System。",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { "105", NULL },
         { "110", NULL },
         { "115", NULL },
         { "120", NULL },
         { "125", NULL },
         { "130", NULL },
         { "135", NULL },
         { "140", NULL },
         { "145", NULL },
         { "150", NULL },
         { "155", NULL },
         { "160", NULL },
         { "165", NULL },
         { "170", NULL },
         { "175", NULL },
         { "180", NULL },
         { "185", NULL },
         { "190", NULL },
         { "195", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_filter",
      "音频过滤",
      "启用音频低通滤镜，以更好地模拟MD1型机的声音特性。",
      {
         { "disabled", "禁用" },
         { "low-pass", "Low-Pass" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lowpass_range",
      "低通滤镜强度%",
      "设置低通滤镜的截断频率。\n"
      "值越高，可察觉到的过滤强度越高，因为更宽范围的高频扩展被减弱了。",
      {
         { "5",  NULL },
         { "10", NULL },
         { "15", NULL },
         { "20", NULL },
         { "25", NULL },
         { "30", NULL },
         { "35", NULL },
         { "40", NULL },
         { "45", NULL },
         { "50", NULL },
         { "55", NULL },
         { "60", NULL },
         { "65", NULL },
         { "70", NULL },
         { "75", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { NULL, NULL },
      },
      "60"
   },
#ifdef HAVE_EQ
   {
      "genesis_plus_gx_audio_eq_low",
      "EQ低频",
      "调整内置音频均衡器的低音频带。",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_mid",
      "EQ中频",
      "调整内置音频均衡器的中音频带。",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_high",
      "EQ高频",
      "调整内置音频均衡器的高音频带。",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
#endif
   {
      "genesis_plus_gx_blargg_ntsc_filter",
      "Blargg NTSC滤镜",
      "应用一个视频滤镜来模拟不同的NTSC电视信号。",
      {
         { "disabled",   "禁用" },
         { "monochrome", "单色" },
         { "composite",  "复合视频" },
         { "svideo",     "S-Video" },
         { "rgb",        "RGB" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lcd_filter",
      "LCD鬼影滤镜",
      "应用一个图像鬼影滤镜，来模拟Game Gear和Genesis Nomad的LCD屏幕显示特性。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_overscan",
      "边界",
      "启用此设置显示屏幕上下或者左右的过扫描区域。\n"
      "这些区域通常被标准电视的边框隐藏了。",
      {
         { "disabled",   "禁用" },
         { "top/bottom", "上/下" },
         { "left/right", "左/右" },
         { "full",       "全部" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gg_extra",
      "扩展Game Gear屏幕",
      "强制Game Gear游戏以SMS模式运行，提高分辨率到256x192。\n"
      "可能会显示额外的内容，但是通常是显示一个含有无效图像数据的边框。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_aspect_ratio",
      "内核提供宽高比",
      "选择期望的显示宽高比。\n"
      "此项设置只有当RetroArch的宽高比设为‘内核提供’时有效。",
      {
         { "auto",     "自动" },
         { "NTSC PAR", "NTSC像素宽高比" },
         { "PAL PAR",  "PAL像素宽高比" },
      },
      "auto"
   },
   {
      "genesis_plus_gx_render",
      "隔行模式2输出",
      "隔行模式2允许MD/Genesis在每帧绘制额外的扫描线，输出双倍高度的图像（320x448）\n"
      "此功能由'Sonic the Hedgehog 2'和'Combat Cars'多人游戏模式使用。\n"
      "'双场'模拟原始硬件，输出更锐利的图像同时伴随抖动/隔行扫描效果。\n"
      "'单场'应用一个去隔行滤镜，产生稳定的图像但是可能导致轻微模糊。",
      {
         { "single field", "Single Field" },
         { "double field", "Double Field" },
         { NULL, NULL },
      },
      "single field"
   },
   {
      "genesis_plus_gx_gun_cursor",
      "显示光枪准心",
      "在使用'MD Menacer', 'MD Justifiers'和'MS Light Phaser'输入设备时显示光枪准心。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gun_input",
      "光枪输入",
      "使用鼠标控制的‘光枪’或者‘触屏’输入。",
      {
         { "lightgun",    "光枪" },
         { "touchscreen", "触屏" },
         { NULL, NULL },
      },
      "lightgun"
   },
   {
      "genesis_plus_gx_invert_mouse",
      "鼠标Y轴反向",
      "使用'MD鼠标'输入设备时反向Y轴。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
#ifdef HAVE_OVERCLOCK
   {
      "genesis_plus_gx_overclock",
      "CPU速度",
      "对模拟CPU进行超频。可以减少拖慢，但可能导致其他问题。",
      {
         { "100%", NULL },
         { "125%", NULL },
         { "150%", NULL },
         { "175%", NULL },
         { "200%", NULL },
         { NULL, NULL },
      },
      "100%"
   },
#endif
   {
      "genesis_plus_gx_no_sprite_limit",
      "移除每扫描线角色限制",
      "移除每扫描线的8个（Master System）或20个（MD/Genesis）角色数量硬件限制。\n"
      "可以减少闪烁，但是可能导致视觉效果不正常，因为有些游戏使用此限制来产生特殊效果。",
      {
         { "disabled", "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */

	struct retro_core_option_definition option_defs_tr[] = {
   {
      "genesis_plus_gx_system_hw",
      "Sistem Donanımı",
      "Yüklenen içeriği belirli bir öykünmüş konsolla çalıştırır. 'Otomatik' mevcut oyun için en uygun sistemi seçecektir.",
      {
         { "auto",                 "Otomatik"               },
         { "sg-1000",              "SG-1000"            },
         { "sg-1000 II",           "SG-1000 II"         },
         { "mark-III",             "Mark III"           },
         { "master system",        "Master System"      },
         { "master system II",     "Master System II"   },
         { "game gear",            "Game Gear"          },
         { "mega drive / genesis", "Mega Drive/Genesis" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_region_detect",
      "Sistem Bölgesi",
      "Sistemin hangi bölgeden olduğunu belirtin. Game Gear dışındaki konsollar için 'PAL' 50hz, 'NTSC' 60hz'dir. Yanlış bölge seçiliyse, oyunlar normalden daha hızlı veya daha yavaş çalışabilir.",
      {
         { "auto",    "Otomatik"   },
         { "ntsc-u",  "NTSC-U" },
         { "pal",     "PAL"    },
         { "ntsc-j",  "NTSC-J" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_force_dtack",
      "Sistem Kilidi",
      "Geçersiz adres erişimi gerçekleştirirken gerçek donanımda meydana gelen sistem kilitlemelerine öykünün. Bu, yalnızca doğru işlem için yasadışı davranışa dayanan belirli demolar ve homebrew oynatılırken devre dışı bırakılmalıdır.",
      {
         { "enabled",  "Etkinleştir" },
         { "disabled",  "Devre Dışı" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_bios",
      "Sistem Önyükleme ROM'u",
      "RetroArch'ın sistem dizininde varsa, öykünülmüş donanım için resmi BIOS/önyükleyici kullanın. Konsola özgü başlangıç sırası/animasyonu görüntüler, ardından yüklü içeriği çalıştırır.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_bram",
      "CD Sistemi BRAM'i",
      "Sega CD içeriği çalıştırılırken, belirli bir bölgedeki tüm oyunlar arasında (BIOS başına) tek bir kayıt dosyasının paylaşılmasını mı yoksa her oyun için ayrı bir kayıt dosyası oluşturup oluşturmamayı (Oyun Başına) belirtir. Sega CD'sinin sınırlı bir dahili depolama alanına sahip olduğunu ve yalnızca bir avuç başlık için yeterli olduğunu unutmayın. Boşluktan kaçınmak için 'Oyun Başına' ayarı önerilir.",
      {
         { "per bios", "BIOS Başına" },
         { "per game", "Oyun Başına" },
         { NULL, NULL },
      },
      "per bios"
   },
   {
      "genesis_plus_gx_addr_error",
      "68K Adres Hatası",
      "Genesis CPU (Motorola 68000), hizalanmamış hafıza erişimi gerçekleştirmeye çalışırken bir Adres Hatası (kilitlenme) üretir. '68K Adres Hatası' özelliğini etkinleştirmek bu davranışı simüle eder. ROM hacklerini oynarken sadece devre dışı bırakılmalıdır, çünkü bunlar daha az doğru emülatörler kullanılarak geliştirilir ve doğru işlem için geçersiz RAM erişimine güvenebilir.",
      {
         { "enabled",  "Etkinleştir" },
         { "disabled",  "Devre Dışı" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "genesis_plus_gx_lock_on",
      "Kartuş Kilitleme",
      "Kilitleme Teknolojisi, eski bir oyunun genişletilmiş veya değiştirilmiş bir oyun için özel bir kartuşun geçiş portuna bağlanmasına izin veren bir Genesis özelliğidir. Bu seçenek, hangi tür 'özel kilitleme' kartuşunun taklit edileceğini belirler. RetroArch'ın sistem dizininde ilgili bir bios dosyası bulunmalıdır.",
      {
         { "disabled",            "Devre Dışı" },
         { "game genie",          "Game Genie" },
         { "action replay (pro)", "Action Replay (Pro)" },
         { "sonic & knuckles",    "Sonic & Knuckles" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_ym2413",
      "Master System FM (YM2413)",
      "Gelişmiş ses çıkışı için bazı Sega Mark III / Master System oyunları tarafından kullanılan FM Ses Ünitesinin emülasyonunu etkinleştirin.",
      {
         { "auto",     "Otomatik" },
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_ym2612",
      "Mega Drive / Genesis FM",
#ifdef HAVE_YM3438_CORE
      "Mega Drive / Genesis'in FM sentezleyicisini (ana ses üreteci) taklit etmek için kullanılan yöntemi seçin. 'MAME' seçenekleri hızlı ve çoğu sistemde tam hızda çalışıyor. 'Nuke' seçenekleri döngüde doğrudur, çok kaliteli ve önemli CPU gereksinimlerine sahiptir. 'YM2612' yongası, orijinal Model 1 Genesis tarafından kullanılır. 'YM3438' daha sonra Genesis revizyonlarında kullanılır.",
#else
      "Mega Drive / Genesis'in FM sentezleyicisini (ana ses üreteci) taklit etmek için kullanılan yöntemi seçin. 'YM2612' yongası, orijinal Model 1 Genesis tarafından kullanılır. 'YM3438' daha sonra Genesis revizyonlarında kullanılır.",
#endif
      {
         { "mame (ym2612)",          "MAME (YM2612)" },
         { "mame (asic ym3438)",     "MAME (ASIC YM3438)" },
         { "mame (enhanced ym3438)", "MAME (Enhanced YM3438)" },
#ifdef HAVE_YM3438_CORE
         { "nuked (ym2612)",         "Nuked (YM2612)" },
         { "nuked (ym3438)",         "Nuked (YM3438)" },
#endif
         { NULL, NULL },
      },
      "mame (ym2612)"
   },
   {
      "genesis_plus_gx_sound_output",
      "Ses Çıkışı",
      "Stereo veya mono ses üretimini seçin.",
      {
         { "stereo", "Stereo" },
         { "mono",   "Mono" },
         { NULL, NULL },
      },
      "stereo"
   },
   {
      "genesis_plus_gx_psg_preamp",
      "PSG Preamp Level",
      "Master System, Game Gear ve Genesis'de bulunan öykünmüş SN76496 4 kanallı Programlanabilir Ses Üretecinin ses ön yükselticisi seviyesini ayarlayın.",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { "105", NULL },
         { "110", NULL },
         { "115", NULL },
         { "120", NULL },
         { "125", NULL },
         { "130", NULL },
         { "135", NULL },
         { "140", NULL },
         { "145", NULL },
         { "150", NULL },
         { "155", NULL },
         { "160", NULL },
         { "165", NULL },
         { "170", NULL },
         { "175", NULL },
         { "180", NULL },
         { "185", NULL },
         { "190", NULL },
         { "195", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "150"
   },
   {
      "genesis_plus_gx_fm_preamp",
      "FM Preamp Level",
      "Öykünülmüş Sega Mark III/Master System FM Ses Ünitesinin ses ön yükselticisi seviyesini ayarlayın.",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { "105", NULL },
         { "110", NULL },
         { "115", NULL },
         { "120", NULL },
         { "125", NULL },
         { "130", NULL },
         { "135", NULL },
         { "140", NULL },
         { "145", NULL },
         { "150", NULL },
         { "155", NULL },
         { "160", NULL },
         { "165", NULL },
         { "170", NULL },
         { "175", NULL },
         { "180", NULL },
         { "185", NULL },
         { "190", NULL },
         { "195", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_filter",
      "Ses Filtresi",
      "Model 1 Genesis'in karakteristik sesini daha iyi simüle etmek için düşük geçişli bir ses filtresini etkinleştirin.",
      {
         { "disabled",  "Devre Dışı" },
         { "low-pass", "Low-Pass" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lowpass_range",
      "Low-Pass Filtresi %",
      "Düşük ses geçiş filtresinin kesme frekansını belirtin. Daha yüksek bir değer, yüksek frekans spektrumunun daha geniş bir aralığı azaltıldığı için filtrenin algılanan gücünü arttırır.",
      {
         { "5",  NULL },
         { "10", NULL },
         { "15", NULL },
         { "20", NULL },
         { "25", NULL },
         { "30", NULL },
         { "35", NULL },
         { "40", NULL },
         { "45", NULL },
         { "50", NULL },
         { "55", NULL },
         { "60", NULL },
         { "65", NULL },
         { "70", NULL },
         { "75", NULL },
         { "80", NULL },
         { "85", NULL },
         { "90", NULL },
         { "95", NULL },
         { NULL, NULL },
      },
      "60"
   },
#ifdef HAVE_EQ
   {
      "genesis_plus_gx_audio_eq_low",
      "EQ Low",
      "Dahili ses ekolayzırın düşük aralık bandını ayarlayın.",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_mid",
      "EQ Mid",
      "Dahili ses ekolayzerinin orta aralık bandını ayarlayın.",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "genesis_plus_gx_audio_eq_high",
      "EQ High",
      "Dahili ses ekolayzerinin yüksek aralık bandını ayarlayın.",
      {
         { "0",   NULL },
         { "5",   NULL },
         { "10",  NULL },
         { "15",  NULL },
         { "20",  NULL },
         { "25",  NULL },
         { "30",  NULL },
         { "35",  NULL },
         { "40",  NULL },
         { "45",  NULL },
         { "50",  NULL },
         { "55",  NULL },
         { "60",  NULL },
         { "65",  NULL },
         { "70",  NULL },
         { "75",  NULL },
         { "80",  NULL },
         { "85",  NULL },
         { "90",  NULL },
         { "95",  NULL },
         { "100", NULL },
         { NULL, NULL },
      },
      "100"
   },
#endif
   {
      "genesis_plus_gx_blargg_ntsc_filter",
      "Blargg NTSC Filtresi",
      "Çeşitli NTSC TV sinyallerini taklit etmek için bir video filtresi uygulayın.",
      {
         { "disabled",   "Devre Dışı" },
         { "monochrome", "Monochrome" },
         { "composite",  "Composite" },
         { "svideo",     "S-Video" },
         { "rgb",        "RGB" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_lcd_filter",
      "LCD Gölgelenme Filtresi",
      "Game Gear ve 'Genesis Nomad' LCD panellerinin ekran özelliklerini taklit etmek için bir görüntü “gölgelenme” filtresi uygulayın.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_overscan",
      "Çerçeveler",
      "Aşırı tarama bölgelerini ekranın üstünde/altında ve/veya sol/sağında görüntülemek için bunu etkinleştirin. Bunlar normalde standart tanımlı bir televizyonun kenarındaki çerçeve tarafından gizlenir.",
      {
         { "disabled",   "Devre Dışı" },
         { "top/bottom", "Üstünde/Atında" },
         { "left/right", "Sol/Sağ" },
         { "full",       "Tam" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gg_extra",
      "Game Gear Genişletilmiş Ekran",
      "Game Gear oyunlarını 256x192 çözünürlüğe sahip 'SMS' modunda çalıştırmaya zorlar. Ek içerik gösterebilir, ancak genellikle bozuk/istenmeyen resim verilerinin kenarlığını görüntüler.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_aspect_ratio",
      "Çekirdek Tarafından Sağlanan En Boy Oranı",
      "Tercih edilen içerik en boy oranını seçin. Bu, yalnızca RetroArch’ın en boy oranı Video ayarlarında 'Çekirdek Tarafından Sağlanan' olarak ayarlandığında uygulanacaktır.",
      {
         { "auto",     "Otomatik" },
         { "NTSC PAR", NULL },
         { "PAL PAR",  NULL },
      },
      "auto"
   },
   {
      "genesis_plus_gx_render",
      "Geçmeli Mod 2 Çıkışı",
      "Geçmeli Mod 2, Genesis'e, her kareye alternatif tarama çizgileri çizerek (bu, 'Sonic the Hedgehog 2' ve 'Savaş Arabaları' çok oyunculu modları tarafından kullanılır) çift yükseklikte (yüksek çözünürlüklü) 320x448 görüntü vermesini sağlar. 'Çift Alan' orijinal donanımı taklit eder, titreyen/birbirine geçen eserler ile keskin bir görüntü oluşturur. 'Tek Alan', görüntüyü dengeleyen ancak hafif bulanıklığa neden olan, birbirinin yerine geçen bir filtredir.",
      {
         { "single field", "Tek Alan" },
         { "double field", "Çift Alan" },
         { NULL, NULL },
      },
      "single field"
   },
   {
      "genesis_plus_gx_gun_cursor",
      "Light Gun Göstergesini Göster",
      "'MD Menacer', 'MD Justifiers' ve 'MS Light Phaser' giriş cihazı tiplerini kullanırken Light Gun göstergelerini gösterin.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "genesis_plus_gx_gun_input",
      "Light Gun Girdisi",
      "Fare kontrollü 'Light Gun' veya 'Dokunmatik Ekran' girişi kullanın.",
      {
         { "lightgun",    "Light Gun" },
         { "touchscreen", "Dokunmatik Ekran" },
         { NULL, NULL },
      },
      "lightgun"
   },
   {
      "genesis_plus_gx_invert_mouse",
      "Fare Y Eksenini Ters Çevir",
      "'MD Fare' giriş cihazı türünün Y eksenini ters çevirir.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
#ifdef HAVE_OVERCLOCK
   {
      "genesis_plus_gx_overclock",
      "CPU Hızı",
      "Öykünülmüş CPU hız aşırtması. Yavaşlamayı azaltabilir, ancak aksaklığa neden olabilir.",
      {
         { "100%", NULL },
         { "125%", NULL },
         { "150%", NULL },
         { "175%", NULL },
         { "200%", NULL },
         { NULL, NULL },
      },
      "100%"
   },
#endif
   {
      "genesis_plus_gx_no_sprite_limit",
      "Satır Başına Sprite Limitini Kaldır",
      "8 (Ana Sistem) veya 20 (Genesis) tarama başına sprite donanım sınırını kaldırır. Bu, titremeyi azaltır ancak bazı oyunlar özel efektler oluşturmak için donanım sınırını kullandığı için görsel hatalara neden olabilir.",
      {
         { "disabled",  "Devre Dışı" },
         { "enabled",  "Etkinleştir" },
         { NULL, NULL },
      },
      "disabled"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

#ifdef __cplusplus
}
#endif

#endif
