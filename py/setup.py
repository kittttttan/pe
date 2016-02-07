#!/usr/bin/env python
from distutils.core import setup, Command
# from Cython.Build import cythonize

setup(
    name = 'pe',
    version='1.0.0',
    description='solve project euler',
    author='kittttttan',
    url='https://github.com/kittttttan/pe/py',
    license='MIT',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
    ],
    # ext_modules = cythonize("pe/runner.py"),
    # package_dir={'': 'pe'},
    packages=['pe'],
)
