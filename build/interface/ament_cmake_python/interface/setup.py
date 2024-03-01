from setuptools import find_packages
from setuptools import setup

setup(
    name='interface',
    version='0.0.0',
    packages=find_packages(
        include=('interface', 'interface.*')),
)
