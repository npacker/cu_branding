(function($) {
	$(document).ready(function() {
		$('#cu-search-form').submit(function(event) {
			var searchString = '/search/node/' + $('#cu-search-input').val();
			
			if (window.location.hostname === 'assettdev.colorado.edu') {
				var pathArray = window.location.pathname.split('/'),
					i = 0;
						
				while (!pathArray[i]) {
					++i;
				}
				
				if (pathArray[i] === 'drupalconv') {
					window.location = window.location.protocol + '//assettdev.colorado.edu/drupalconv/' + pathArray[i + 1] + searchString;
				} else {
					window.location = window.location.protocol + '//assettdev.colorado.edu/' + pathArray[i] + searchString;
				}
			} else {
				window.location = window.location.protocol + '//' + window.location.hostname + searchString;
			}
			
			event.preventDefault();
		});
	});
})(jQuery);