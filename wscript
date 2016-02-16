import os

top = '.'
out='build'

VERSION = '0.1'
SOFTWARE_NAME = 'cem'

def options(opt):
  opt.load('compiler_c')

def configure(conf):
  conf.check_waf_version(mini='1.8.17')
  conf.load('compiler_c')
  conf.find_program('touch', var='TOUCH')
  conf.check_cc(function_name='printf', header_name='stdio.h', mandatory=True)
  conf.check_cc(function_name='calloc', header_name='stdlib.h', mandatory=True)
  conf.define('LIBCEM_VERSION', VERSION)
  conf.check_cfg(package='gtk+-3.0', args=['--cflags','--libs'],
    uselib_store='GTK3')
  conf.write_config_header('config.h')


def build(bld):
  bld.recurse(['src'])
  print(out)
