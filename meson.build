project(
  'numpy_mem_handler',
  'c', 'cython',
  version: '1.0',
  meson_version: '== 1.8.3',
  default_options: [
    'c_std=c11',
  ],
)

cc = meson.get_compiler('c')
cython = meson.get_compiler('cython')
cython_program = find_program(cython.cmd_array()[0])

cython_gen = generator(cython_program,
  arguments : ['@INPUT@', '--output-file', '@OUTPUT@'],
  output : '@BASENAME@.c',
)

py = import('python').find_installation(pure: false)

incdir_numpy = run_command(py,
  ['-c', 'import os; os.chdir(".."); import numpy; print(numpy.get_include())'],
  check : true
).stdout().strip()
np_dep = declare_dependency(include_directories: incdir_numpy)

py.extension_module(
  'numpy_mem_handler',
  [cython_gen.process('numpy_mem_handler.pyx'), 'src' / 'numpy_mem_handler.h'],
  dependencies: [np_dep],
  install: true
)
