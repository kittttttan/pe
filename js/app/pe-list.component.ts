import {Component} from 'angular2/core';
import {Router} from 'angular2/router';

@Component({
  selector: 'pe-list',
  templateUrl: 'app/pe-list.component.html'
})
export class PeListComponent {
  public problems: number[];

  constructor(private _router: Router) {
    // TODO
    this.problems = [1, 2];
  }

  public gotoDetail(problem: number): void {
    this._router.navigate([`Pe${problem}`]);
  }

  public onSelect(n: number): void {
    this.gotoDetail(n);
  }
}
