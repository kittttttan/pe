/// <reference path="../node_modules/@types/jasmine/index.d.ts" />
import Benchmark from '@ktn/benchmark';
import {Pe1, Pe2, Pe3} from '../';

describe('Pe', ()=> {
  const bm: Benchmark = Benchmark.bm({loop: 1});
  bm.add('1', () =>{
    it('1', ()=> {
      console.log('test 1');
      expect(Pe1.solve()).toEqual(234168);
      expect(Pe1.solveLoop()).toEqual(234168);
    });
  });

  bm.add('2', () =>{
    it('2', ()=> {
      expect(Pe2.solve()).toEqual(4613732);
    });
  });

  bm.add('3', () =>{
    it('3', ()=> {
      expect(Pe3.solve()).toEqual([71, 839, 1471, 6857]);
    });
  });

  bm.run();
});
