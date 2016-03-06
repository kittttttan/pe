import {Component} from 'angular2/core';
import {Pe2} from './pe/pe2';

@Component({
  selector: 'pe2',
  templateUrl: 'app/pe2.component.html'
})
export class Pe2Component {
  public n: number = 4000000;
  public calc = Pe2.pe2;
}
