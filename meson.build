project('gtkhello', 'c',
	version : '0.1',
	license : 'BSD2CLAUSE',
	default_options : [ 'c_std=c11' ],
	meson_version : '>=0.40.0')

# Compiler setup
cc = meson.get_compiler('c')
cflags = ['-Wall', '-Werror', '-fvisibility=hidden']
add_project_arguments(cflags, language: 'c')

# config.h
config_h = configuration_data()
config_h_inc = include_directories('.')
if get_option('buildtype') == 'debug' or get_option('buildtype') == 'debugoptimized'
	config_h.set_quoted('MESON_BUILD_ROOT', meson.build_root())
else
	config_h.set_quoted('MESON_BUILD_ROOT', '')
endif

# dependencies
pkgconfig = import('pkgconfig')
gtk_dep = dependency('gtk+-3.0')

# Include directories
includes_src = include_directories('src')

# options
have_hello = get_option('hello')
have_goodbye = get_option('goodbye')

if have_hello and have_goodbye
	error('hello and goodbye can\'t both be enabled')
endif

if have_hello
	config_h.set('WANT_HELLO', 1)
endif

if have_goodbye
	config_h.set('WANT_GOODBYE', 1)
endif

src_gtkhello = [ 'src/main.c',
	'src/msg.h',
	'src/msg.c'
]

executable('gtkhello',
	src_gtkhello,
	dependencies : [gtk_dep],
	include_directories : [includes_src],
	install : true
)

# output files
configure_file(output : 'config.h', install : false, configuration : config_h)
