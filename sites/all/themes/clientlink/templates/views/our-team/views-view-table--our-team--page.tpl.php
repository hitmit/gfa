<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

?>

<div class="col-12">
<table>
	<tbody scope="row">
		<tr class="row m-0" scope="row">
			<?php foreach ($rows as $row_count => $row): ?>
				<td class="col-md-3 col-sm-12 mt-3 mb-3 content team-item testing" scope="col" >
					<?php foreach ($row as $field => $content): ?>
						<?php print $content; ?>
					<?php endforeach; ?>
				</td>
			<?php endforeach; ?>
		</tr>
	</tbody>
</table>
</div>
